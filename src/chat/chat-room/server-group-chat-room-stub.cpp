/*
 * server-group-chat-room-stub.cpp
 * Copyright (C) 2010-2017 Belledonne Communications SARL
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "core/core.h"

#include "server-group-chat-room-p.h"

// =============================================================================

using namespace std;

LINPHONE_BEGIN_NAMESPACE

// -----------------------------------------------------------------------------

shared_ptr<Participant> ServerGroupChatRoomPrivate::addParticipant (const IdentityAddress &) {
	return nullptr;
}

void ServerGroupChatRoomPrivate::confirmCreation () {}

void ServerGroupChatRoomPrivate::confirmJoining (SalCallOp *) {}

shared_ptr<Participant> ServerGroupChatRoomPrivate::findRemovedParticipant (
	const shared_ptr<const CallSession> &
) const {
	return nullptr;
}

string ServerGroupChatRoomPrivate::generateConferenceId () const {
	return "";
}

void ServerGroupChatRoomPrivate::removeParticipant (const shared_ptr<const Participant> &) {}

void ServerGroupChatRoomPrivate::subscribeReceived (LinphoneEvent *) {}

void ServerGroupChatRoomPrivate::update (SalCallOp *) {}

// -----------------------------------------------------------------------------

void ServerGroupChatRoomPrivate::dispatchMessage (const IdentityAddress &, const Content &) {}

void ServerGroupChatRoomPrivate::storeOrUpdateMessage (const shared_ptr<ChatMessage> &) {}

LinphoneReason ServerGroupChatRoomPrivate::messageReceived (SalOp *, const SalMessage *) {
	return LinphoneReasonNone;
}

void ServerGroupChatRoomPrivate::setConferenceAddress (const IdentityAddress &confAddr) {}

// -----------------------------------------------------------------------------

void ServerGroupChatRoomPrivate::designateAdmin () {}

void ServerGroupChatRoomPrivate::finalizeCreation () {}

bool ServerGroupChatRoomPrivate::isAdminLeft () const {
	return false;
}

// =============================================================================

ServerGroupChatRoom::ServerGroupChatRoom (const shared_ptr<Core> &core, SalCallOp *op) :
ChatRoom(*new ServerGroupChatRoomPrivate, core, ChatRoomId(IdentityAddress(op->get_to()), IdentityAddress(op->get_to()))),
LocalConference(core, IdentityAddress(op->get_to()), nullptr) {}

int ServerGroupChatRoom::getCapabilities () const {
	return 0;
}

bool ServerGroupChatRoom::canHandleParticipants () const {
	return false;
}

void ServerGroupChatRoom::addParticipant (const IdentityAddress &, const CallSessionParams *, bool) {}

void ServerGroupChatRoom::addParticipants (const list<IdentityAddress> &, const CallSessionParams *, bool) {}

const IdentityAddress &ServerGroupChatRoom::getConferenceAddress () const {
	return LocalConference::getConferenceAddress();
}

void ServerGroupChatRoom::removeParticipant (const shared_ptr<const Participant> &) {}

void ServerGroupChatRoom::removeParticipants (const list<shared_ptr<Participant>> &) {}

shared_ptr<Participant> ServerGroupChatRoom::findParticipant (const IdentityAddress &) const {
	return nullptr;
}

shared_ptr<Participant> ServerGroupChatRoom::getMe () const {
	return nullptr;
}

int ServerGroupChatRoom::getNbParticipants () const {
	return 0;
}

list<shared_ptr<Participant>> ServerGroupChatRoom::getParticipants () const {
	return LocalConference::getParticipants();
}

void ServerGroupChatRoom::setParticipantAdminStatus (shared_ptr<Participant> &, bool) {}

const string &ServerGroupChatRoom::getSubject () const {
	return LocalConference::getSubject();
}

void ServerGroupChatRoom::setSubject (const string &) {}

void ServerGroupChatRoom::join () {}

void ServerGroupChatRoom::leave () {}

// -----------------------------------------------------------------------------

void ServerGroupChatRoom::onChatMessageReceived(const shared_ptr<ChatMessage> &msg) {}

void ServerGroupChatRoom::onCallSessionStateChanged (
	const shared_ptr<const CallSession> &,
	LinphoneCallState,
	const string &
) {}

LINPHONE_END_NAMESPACE
