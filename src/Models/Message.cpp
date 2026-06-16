#include "Message.h"

namespace Models {

Message::Message(User from, User to, std::string content)
	: from(std::move(from)), to(std::move(to)), content(std::move(content))
{
}

User Message::GetDestination() const
{
	return to;
}

User Message::GetOrigin() const
{
	return from;
}

std::string Message::GetContent() const
{
	return content;
}

} // namespace Models