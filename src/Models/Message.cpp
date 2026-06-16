#include "Message.h"

namespace Models {

Message::Message(User from, User to, std::string content)
	: from(std::move(from)), to(std::move(to)), content(std::move(content))
{
}

} // namespace Models