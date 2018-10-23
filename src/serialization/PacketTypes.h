#pragma once

#include <cstdint>

enum class PacketType : int8_t
{
	RegisterRequest,
	LoginRequest,
	QueryAllMessagesRequest,
	QueryAllMessagesResponse,
	SendMessageRequest
};
