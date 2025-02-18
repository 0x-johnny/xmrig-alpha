#ifndef XMRIG_STRATEGYUNICITY_H
#define XMRIG_STRATEGYUNICITY_H

#include "net/strategies/DonateStrategy.h"
#include "net/Client.h"
#include "base/kernel/interfaces/IStrategy.h"
#include <string>
#include <vector>

namespace xmrig {

class StrategyUnicity : public IStrategy
{
public:
    StrategyUnicity(Controller *controller, const char *url, const char *user, const char *pass);
    ~StrategyUnicity() override;

    void tick(uint64_t now) override;
    void connect() override;
    void submitJob(const Job &job);
    void handleResult(const JobResult &result);

    // Implement pure virtual functions from IStrategy
    bool isActive() const override;
    IClient *client() const override;
    int64_t submit(const JobResult &result) override;
    void resume() override;
    void setAlgo(const Algorithm &algo) override;
    void setProxy(const ProxyUrl &proxy) override;
    void stop() override;

private:
    std::string m_url;
    std::string m_user;
    std::string m_pass;
    std::vector<Client *> m_clients;
};

} // namespace xmrig

#endif // XMRIG_STRATEGYUNICITY_H