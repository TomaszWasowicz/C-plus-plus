#include <optional>
#include <string>

std::string stringify(int v)
{
    return std::to_string(v);
}

int integrify(const std::string& s)
{
    return std::stoi(s);
}

std::optional<int> fetch_from_db()
{
    return 42;
}

std::optional<int> x;

auto r1 = x.transform(stringify).transform(integrify);

x = 42;

auto r2 = x.transform(stringify).transform(integrify);

auto r3 = x.and_then([](int x) -> std::optional<std::string> {
    if (x == 42)
        return std::optional<std::string>("Answer to the ultimate question");
    else
        return std::nullopt;
    });

x = std::nullopt;
auto r4 = x.or_else(fetch_from_db);

auto r5 = fetch_from_db().or_else([]() -> std::optional<int> {
    return std::optional<int>(42);
    }).transform([](int x) -> double {
        return x * x;
        }).and_then([](double x) -> std::optional<std::string> {
            if (x > 0) {
                return std::optional<std::string>("42");
            }
            else {
                return std::nullopt;
            }
            }).or_else([]() -> std::optional<std::string> {
                return std::optional<std::string>("Empty");
                });
