//
// Created by inql on 15.11.18.
//

#include <PlayerDisconnectedPacket.h>

#include "PlayerDisconnectedPacket.h"

PlayerDisconnectedPacket::PlayerDisconnectedPacket() : BasePacket(PT_PLAYER_DISCONNECTED, PLAYERDISCONNECTED_PACKET_SIZE) {

}

PlayerDisconnectedPacket::PlayerDisconnectedPacket(Uint8 id):PlayerDisconnectedPacket() {
    setId(id);
}

PlayerDisconnectedPacket::~PlayerDisconnectedPacket() {

}

void PlayerDisconnectedPacket::setId(Uint8 id) {
    data[1] = id;
}


