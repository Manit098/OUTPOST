#include <crow.h>
#include <nlohmann/json.hpp>



using json = nlohmann::json;

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/health")
    ([] {
        json response = {
            {"status", "ok"},
            {"service", "outpost-api"},
            {"version", "1.0.0"}
        };

        return crow::response{
            200,
            response.dump()
        };
    });

    CROW_ROUTE(app, "/")
    ([] {
        return "OUTPOST Engine API is running.";
    });
    
    app.port(5500)
       .bindaddr("127.0.0.1")
       .run();

    return 0;
}
