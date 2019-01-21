//
// Created by inql on 20.11.18.
//
#include "Main.h"

PlayerJoinedPacket::PlayerJoinedPacket():BasePacket(PT_PLAYER_JOINED,PLAYERJOINED_PACKET_SIZE) {
    for(int i=2; i<12; i++){
        data[i] = 0;
    }
}

//PlayerJoinedPacket::PlayerJoinedPacket(Uint8 id):PlayerJoinedPacket() {
//    setId(id);
//}

PlayerJoinedPacket::~PlayerJoinedPacket() = default;

void PlayerJoinedPacket::setId(Uint8 id) {
    data[1] = id;
}

Uint8 PlayerJoinedPacket::getId() {
    return data[1];
}

void PlayerJoinedPacket::print() const {
    std::cout << "Player ID: " << (int)data[1]<< " nickname: "<< getNickname()  << " has joined." << std::endl;
}

void PlayerJoinedPacket::setNickname(std::string nickname) {
    for(int i =0; i<nickname.length(); i++){
        data[i+2] = (Uint8)nickname[i];
    }
}

std::string PlayerJoinedPacket::getNickname() const
{
    std::string nickname;
    char letter;
    for(int i=2; i<12;i++)
    {
        if (data[i]==0)
            break;
        else
            {
            letter = data[i];
            nickname.push_back(letter);
        }
    }
    return nickname;
}
