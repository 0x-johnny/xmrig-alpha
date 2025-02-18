#ifndef XMRIG_STRATEGYUNICITY_H
#define XMRIG_STRATEGYUNICITY_H

#include "net/strategies/DonateStrategy.h" // Include the existing strategy header
#include "net/Client.h"
#include <string>
#include <vector>

namespace xmrig {

class StrategyUnicity : public IStrategy // Ensure it inherits from the correct base class
{
public:
    StrategyUnicity(Controller *controller, const char *url, const char *user, const char *pass);
    ~StrategyUnicity() override;

    void tick(uint64_t now) override;
    void connect() override;
    void submitJob(const Job &job);
    void handleResult(const JobResult &result);

private:
    std::string m_url;
    std::string m_user;
    std::string m_pass;
    std::vector<Client *> m_clients;
};

} // namespace xmrig

#endif // XMRIG_STRATEGYUNICITY_H