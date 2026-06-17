#include "Message.h"

namespace Models {

Message::Message(User sender, User receiver, std::string content)
	: sender(std::move(sender)), receiver(std::move(receiver)), content(std::move(content))
{
}

User Message::GetDestination() const
{
	return receiver;
}

User Message::GetOrigin() const
{
	return sender;
}

std::string Message::GetContent() const
{
	return content;
}

} // namespace Models