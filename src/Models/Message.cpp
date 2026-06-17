#include "Message.h"

namespace Models {

Message::Message(User sender, User receiver, std::string content)
	: sender(std::move(sender)), receiver(std::move(receiver)), content(std::move(content))
{
}

User Message::GetReceiver() const
{
	return receiver;
}

User Message::GetSender() const
{
	return sender;
}

std::string Message::GetContent() const
{
	return content;
}

} // namespace Models