#include "Client.h"
#include "base/io/log/Log.h"
#include "base/net/Job.h"
#include "net/strategies/DonateStrategy.h"
#include <rapidjson/document.h>
#include <rapidjson/error/en.h>

xmrig::Client::Client(Controller *controller, const char *url, const char *user, const char *pass) :
    m_controller(controller),
    m_url(url),
    m_user(user),
    m_pass(pass)
{
    connect();
}

xmrig::Client::~Client() = default;

void xmrig::Client::connect()
{
    // Add logic to connect to the Unicity chain
    // For example, creating a new Client instance and connecting to the specified URL
    // This is a placeholder implementation
    Log::info("Connecting to %s with user %s", m_url.c_str(), m_user.c_str());
}

void xmrig::Client::tick(uint64_t now)
{
    // Add logic to handle periodic tasks
    // For example, checking the connection status or submitting results
}

void xmrig::Client::submit(const Job &job)
{
    // Add logic to submit a job to the Unicity chain
    // This is a placeholder implementation
    Log::info("Submitting job to %s", m_url.c_str());
}

void xmrig::Client::handleResponse(const std::string &response)
{
    // Add debug logging to capture the raw JSON response
    Log::debug("Raw JSON response: %s", response.c_str());

    rapidjson::Document doc;
    if (doc.Parse(response.c_str()).HasParseError()) {
        Log::error("JSON decode failed: %s", rapidjson::GetParseError_En(doc.GetParseError()));
        return;
    }

    // Check if the response contains a result
    if (doc.HasMember("result")) {
        const rapidjson::Value &result = doc["result"];
        // Process the result
        if (result.HasMember("capabilities")) {
            // Example: Log capabilities
            Log::info("Capabilities: %s", result["capabilities"].GetString());
        }
        if (result.HasMember("target")) {
            // Example: Log target
            Log::info("Target: %s", result["target"].GetString());
        }
        // Add more processing as needed
    } else {
        Log::error("No 'result' field in JSON response");
    }

    // Check if the response contains an error
    if (doc.HasMember("error") && !doc["error"].IsNull()) {
        const rapidjson::Value &error = doc["error"];
        // Log the error
        Log::error("Error: %s", error.GetString());
    } else {
        Log::info("No 'error' field in JSON response");
    }
}