#include <vector>
#include <string>

int main() {
    struct foo {
        foo() {};
        ~foo() = delete;
        foo(const foo&) = delete;
        foo(foo&&) = delete;
        foo& operator = (const foo&) = delete;
        foo& operator = (foo&) = delete;
    };
    //std::vector<foo> a;			//wont compile
    std::vector<std::string> x;
    std::vector<std::string> y {"hiii"};		//wont compile
    //std::vector<std::string> z {"hiii"};		//wont compile because it needs destructor
}

