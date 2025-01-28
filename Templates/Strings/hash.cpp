#include <bits/stdc++.h>
using namespace std;
template<typename Mod>
class Hash {
public:
    Hash() {}
    Hash(const string& s, const char first = 'a', int coeff = 31) {
        int n = (int)s.size(); m_hash.assign(n, 0); m_power.resize(n, 1);

        // h[i] = s[0] + s[1] * coeff + s[2] * coeff^2 + ...
        for(int i = 1; i < n; i++) m_power[i] = coeff * m_power[i - 1];

        m_hash[0] = static_cast<Mod>(s[0] - first + 1);
        for(int i = 1; i < n; i++) m_hash[i] = m_hash[i - 1] + static_cast<Mod>(s[i] - first + 1) * m_power[i];
    }
    const Mod& operator()() const { return m_hash.back(); }
    const Mod& get(int i) const { return m_hash[i]; }
    Mod get(int l, int r) {
        Mod r_hash = m_hash[r], l_hash = l > 0 ? m_hash[l - 1] : static_cast<Mod>(0);
        return (r_hash - l_hash) / m_power[l];
    }

private:
    vector<Mod> m_hash;
    vector<Mod> m_power;
};