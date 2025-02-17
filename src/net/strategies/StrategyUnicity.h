#ifndef XMRIG_STRATEGYUNICITY_H
#define XMRIG_STRATEGYUNICITY_H

#include "base/net/strategies/Strategy.h"

namespace xmrig {

class StrategyUnicity : public Strategy
{
public:
    StrategyUnicity(Controller *controller, const char *url, const char *user, const char *pass);
    ~StrategyUnicity() override;

    void tick(uint64_t now) override;
    void connect() override;

private:
    std::string m_url;
    std::string m_user;
    std::string m_pass;
};

} // namespace xmrig

#endif // XMRIG_STRATEGYUNICITY_H