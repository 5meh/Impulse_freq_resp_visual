#include "fftalgorithm.h"

void FFTAlgorithm::process(std::vector<std::complex<double>>& data, bool inverse = false)
{
    int n = data.size();
    int logN = std::log2(n);

    for (int i = 0; i < n; ++i)
    {
        int j = 0;
        for (int k = 0; k < logN; ++k)
        {
            j = (j << 1) | ((i >> k) & 1);
        }
        if (i < j)
        {
            std::swap(data[i], data[j]);
        }
    }

    for (int s = 1; s <= logN; ++s)
    {
        int m = 1 << s;
        double angle = (inverse ? 2 : -2) * M_PI / m;
        std::complex<double> wm(std::cos(angle), std::sin(angle));

        for (int k = 0; k < n; k += m)
        {
            std::complex<double> w(1.0, 0.0);
            for (int j = 0; j < m / 2; ++j)
            {
                int t = k + j;
                int u = t + m / 2;
                std::complex<double> t1 = w * data[u];
                std::complex<double> t2 = data[t];

                data[u] = t2 - t1;
                data[t] = t2 + t1;

                w *= wm;
            }
        }
    }

    // Нормализация при обратном БПФ
    if (inverse)
    {
        for (int i = 0; i < n; ++i)
        {
            data[i] /= n;
        }
    }
    return args;
}
