#include "Main.h"

Player::Player( int id, std::string nickname ) : _GameObject( {-5000,-5000} , { (int)((double)170*TANKSCALE),(int)((double)130*TANKSCALE) }  , 0 , DYNAMIC )
{
    this->id = id;
    this->nickname = nickname;
    this->actualHp = 20;

    directionFloat=0;
    towerDirection=0;

    moveSpeed = 0;
    directionSpeed = 0;
    towerSpeed = 0;

    sprite = new TankSprite( id , Game::configuration->getScale() );
    collider = new Collider( position , dimensions , direction );

    blocked = {0,0};

    xFloat = position.x;
    yFloat = position.y;
}

void Player::handleEvent( SDL_Event& e )
{
    // not used anymore
}

void Player::PushOut(Vector2D vec)
{
    blocked.x -= vec.x;
    blocked.y -= vec.y;
}

void Player::move()
{
    //collider->update( position , dimensions , direction );
}

void Player::simulate()
{
    float step = Game::windowManager->getStepTime();

    xFloat += cos(double(direction) *M_PI/180) * tankSpeed * step;
    yFloat += sin(double(direction) *M_PI/180) * tankSpeed * step;

    position.x = int(xFloat);
    position.y = int(yFloat);

    directionFloat += rotationSpeed * step ;
    towerDirection += rotationSpeed * step + turretRotationSpeed * step;

    direction = int(directionFloat);
    iTowerDirection = int(towerDirection);
}

void Player::draw( int x0 , int y0 )
{
    double scale = Game::configuration->getScale();

    if (id == Game::netManager->getMyId())
        sprite->draw( { Game::configuration->getDisplayMode()->w/2 , Game::configuration->getDisplayMode()->h/2 } , direction , iTowerDirection , (int)moveSpeed );
    else
        sprite->draw( { int(x0+position.x* scale) , int(y0+position.y*scale) } , direction , iTowerDirection , (int)moveSpeed );
}

void Player::drawInfo( int x0 , int y0 )
{
    double scale = Game::configuration->getScale();
    int drawx = int(position.x * Game::configuration->getScale());
    int drawy = int(position.y * Game::configuration->getScale());


    Game::textManager->draw(nickname,x0+drawx,y0+drawy-90*scale,15*scale,C_BLACK,true);
    Game::textManager->draw("S:"+std::to_string(score)+"D:"+std::to_string(deaths),x0+drawx,y0+drawy-110*scale,15*scale,C_BLACK,true);

    SDL_Rect ramka = {int(x0+drawx-51*scale),int(y0+drawy-70*scale),int(102*scale),int(10*scale)};
    SDL_SetRenderDrawColor( Game::renderer , 0 , 0 , 0 , 0 );
    SDL_RenderFillRect( Game::renderer , &ramka );

    SDL_Rect ramka2 = {int(x0+drawx-50*scale),int(y0+drawy-69*scale), int(actualHp*scale) , int(8*scale) };

    if (actualHp>49) SDL_SetRenderDrawColor( Game::renderer , 100 , 255 , 0 , 0 );
    if (actualHp<50 && actualHp>24) SDL_SetRenderDrawColor( Game::renderer , 175 , 175 , 0 , 0 );
    if (actualHp<25) SDL_SetRenderDrawColor( Game::renderer , 255 , 0 , 0 , 0 );


    SDL_RenderFillRect( Game::renderer , &ramka2 );


//    Game::textManager->draw( std::to_string( position.x ) , x0+position.x , y0+position.y-140 , 15 , C_BLACK , true );
//    Game::textManager->draw( std::to_string( position.y ) ,  x0+position.x , y0+position.y-126 , 15 , C_BLACK , true);
//    Game::textManager->draw( std::to_string( direction ) , x0+position.x , y0+position.y-112 , 15 , C_BLACK , true);
//
//    Game::textManager->draw( std::to_string( (int)tankSpeed ) ,  x0+position.x , y0+position.y-94 , 15 , C_BLACK , true);
//    Game::textManager->draw( std::to_string( (int)rotationSpeed ) ,  x0+position.x , y0+position.y-80 , 15 , C_BLACK , true);
//    Game::textManager->draw( std::to_string( (int)turretRotationSpeed ) ,  x0+position.x , y0+position.y-66 , 15 , C_BLACK , true);

    //Game::textManager->draw( "sp: " + std::to_string( moveSpeed ) ,  150 , 540 );
    //Game::textManager->draw( "dir: " + std::to_string( direction ) ,  150 , 560 );
    //Game::textManager->draw( "xblock: " + std::to_string( blocked.x ) ,  550 , 500 );
    //Game::textManager->draw( "yblock: " + std::to_string( blocked.y ) ,  550 , 530 );
}

int Player::getTowDir() { return iTowerDirection; }

int Player::getDir() { return direction; }

SDL_Point Player::shootPosition()
{
    SDL_Point punkt;
    punkt.x = (int)(position.x+(cos(double(iTowerDirection) *M_PI/180) * 60 * Game::configuration->getScale()));
    punkt.y = (int)(position.y+(sin(double(iTowerDirection) *M_PI/180) * 60 * Game::configuration->getScale()));
    return punkt;
}
SDL_Point Player::smokePosition()
{
    int los = (random()%32)-16;


    SDL_Point punkt;
    punkt.x = (int)(position.x + (cos((direction+los) *M_PI/180) * -50));
    punkt.y = (int)(position.y + (sin((direction+los) *M_PI/180) * -50));
    return punkt;
}

int Player::getId()
{
    return id;
}

void Player::setPosition(SDL_Point position) { this->position=position; xFloat=position.x; yFloat=position.y; }
void Player::setDirection(int direction) { this->direction=direction; this->directionFloat=direction; }
void Player::setTowerDirection(int towerDirection) { this->iTowerDirection=towerDirection; this->towerDirection=towerDirection; }
void Player::setTankSpeed(int tankSpeed) { this->tankSpeed = tankSpeed; }
void Player::setRotationSpeed(int rotationSpeed) { this->rotationSpeed = rotationSpeed; }
void Player::setTurretRotationSpeed(int turretRotationSpeed) { this->turretRotationSpeed = turretRotationSpeed; }

void Player::setFromPacket( CurrentPositionPacket * packet )
{
    this->position = { packet->getX() , packet->getY() };
    this->xFloat = position.x;
    this->yFloat = position.y;
    this->direction=packet->getTankRotation();
    this->directionFloat=direction;
    this->iTowerDirection = packet->getTurretRotation();
    this->towerDirection = iTowerDirection;
    this->tankSpeed = packet->getTankSpeed();
    this->rotationSpeed = packet->getRotationSpeed();
    this->turretRotationSpeed = packet->getTurretRotationSpeed();
    this->actualHp = packet->getActualHp();
    this->score = packet->getScore();
    this->deaths = packet->getDeaths();
    this->updated=true;
}

int Player::getTankSpeed() { return tankSpeed; }

float Player::getTowerSpeed() { return towerSpeed; }

int Player::getTurretRotationSpeed() { return turretRotationSpeed; }

std::string Player::getNickname() {
    return this->nickname;
}

void Player::setActualHp(int actualHp)
{
    this->actualHp = actualHp;
}

void Player::reloadGUI()
{
    sprite->reloadGUI();
}

int Player::getDeaths() const {
    return deaths;
}

void Player::setDeaths(int deaths) {
    Player::deaths = deaths;
}

int Player::getScore() const {
    return score;
}

void Player::setScore(int score) {
    Player::score = score;
}
