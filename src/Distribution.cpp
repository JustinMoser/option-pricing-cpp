#include "Distribution.h"
#include <Math.h>
namespace Math
{
	namespace Statistics
	{
		const long double Distribution::PI(3.141592653589793238L);

		double Distribution::n(double x) //Gaussian (normal) distribution
		{
			double A = 1.0 / sqrt(2.0 * PI);
			return A * exp(-x * x * 0.5);
		}

		double Distribution::N(double x) //Cumulative normal distribution
		{
			double a1(0.4361836);
			double a2(-0.1201676);
			double a3(0.9372980);

			double k(1.0 / (1.0 + (0.33267 * x)));
			
			if (x >= 0.0)
			{
				return 1.0 - n(x) * (a1 * k + (a2 * k * k) + (a3 * k * k * k));
			}
			else
			{
				return 1.0 - N(-x);
			}
		}
	}
}
