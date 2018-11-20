#include "Main.h"

PlayerDisconnectedPacket::PlayerDisconnectedPacket() : BasePacket(PT_PLAYER_DISCONNECTED, PLAYERDISCONNECTED_PACKET_SIZE) {

}

PlayerDisconnectedPacket::PlayerDisconnectedPacket(Uint8 id):PlayerDisconnectedPacket() {
    setId(id);
}

void PlayerDisconnectedPacket::setId(Uint8 id) {
    data[1] = id;
}


