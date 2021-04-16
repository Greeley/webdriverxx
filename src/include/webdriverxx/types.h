#ifndef WEBDRIVERXX_TYPES_H
#define WEBDRIVERXX_TYPES_H

#include <string>
#include <cstdint>

namespace webdriverxx {

typedef uint64_t TimePoint;
typedef uint32_t Duration;
typedef long HTTPCode;

struct Size {
	int width;
	int height;
	Size() : width(0), height(0) {}
	Size(int w, int h) : width(w), height(h) {}
};

struct Rect {
	int x;
	int y;
	int width;
	int height;
	Rect() : x(0), y(0), width(0), height(0) {}
	Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) {}
};

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
};

enum Orientation {
	LANDSCAPE,
	PORTRAIT
};

typedef Point Offset;

struct Cookie {
	enum {
		NoExpiry = 0
	};

	std::string name;
	std::string value;
	std::string path;
	std::string domain;
	bool secure;
	bool http_only;
	int expiry; // seconds since midnight, January 1, 1970 UTC

	Cookie() : secure(false), http_only(false), expiry(NoExpiry) {}
	Cookie(
		const std::string& name,
		const std::string& value,
		const std::string& path = std::string(),
		const std::string& domain = std::string(),
		bool secure = false,
		bool http_only = false,
		int expiry = NoExpiry
		)
		: name(name)
		, value(value)
		, path(path)
		, domain(domain)
		, secure(secure)
		, http_only(http_only)
		, expiry(expiry)
	{}

	bool operator == (const Cookie& c) const {
		return name == c.name
			&& value == c.value
			&& path == c.path
			&& domain == c.domain
			&& secure == c.secure
			&& http_only == c.http_only
			&& expiry == c.expiry
			;
	}
};

namespace timeout {

typedef const char* Type;

Type const Implicit = "implicit";
Type const PageLoad = "page load";
Type const Script = "script";

} // namespace timeout

namespace mouse {
enum Button {
	LeftButton = 0,
	MiddleButton = 1,
	RightButton = 2
};
} // namespace mouse

} // namespace webdriverxx

#endif
