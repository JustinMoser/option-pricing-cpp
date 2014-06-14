//EuropeanOption.cpp
#include "EuropeanOption.h"		//Header file for declarations
#include "Distribution.h"		//Distributions
#include <Math.h>			//For mathematical functions such as expr()

using namespace Math::Statistics;
using namespace Instruments::Options;

namespace Instruments 
{
	namespace Options
	{
		//Kernel Functions
		double EuropeanOption::CallPrice() const 
		{
			return (U * exp((b - r) * T) * Distribution::N(d1) - (K * exp(-r * T) * Distribution::N(d2)));
		}

		double EuropeanOption::PutPrice() const 
		{
			return (K * exp(-r * T) * Distribution::N(-d2) - (U * exp((b - r)*T) * Distribution::N(-d1)));
		}

		double EuropeanOption::CallDelta() const 
		{
			return exp((b - r) * T) * Distribution::N(d1);
		}

		double EuropeanOption::PutDelta() const 
		{
			return exp((b - r) * T) * (Distribution::N(d1) - 1.0);
		}

		//Initialize default option data
		void EuropeanOption::init()
		{
			//Initialize default values
			r = 0.08;
			sig = 0.30;
			K = 65.0;
			T = 0.25;
			
			//U == stock in this case
			U = 60.0;
			//Black and Scholes
			b = r;

			OptType = OT_CALL;

			tmp = sig * sqrt(T);
			d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			d2 = d1 - tmp;
		}

		//Constructors
		EuropeanOption::EuropeanOption()
		{
			//Default constructor: initialize default values
			init();
		}

		EuropeanOption::EuropeanOption(	double assetPrice, 
										double strikePrice, 
										double timeToExpiry, 
										double volatility, 
										double riskFreeRate,
										double dividendYield,
										double costOfCarry,
										OptionType optionType)
		: U(assetPrice)
		, K(strikePrice)
		, T(timeToExpiry)
		, sig(volatility)
		, r(riskFreeRate)
		, b(costOfCarry)
		, q(dividendYield)
		, OptType(optionType)
		{ 
			tmp = sig * sqrt(T);
			d1 = (log(U / K) + (b + (sig * sig) * 0.5) * T) / tmp;
			d2 = (d1 - tmp);
		}


		//Functions that calculate price and sensitivities
		double EuropeanOption::Price() const
		{
			if(OT_CALL == OptType) return CallPrice();
			else return PutPrice();
		}

		double EuropeanOption::Delta() const
		{
			if(OT_CALL == OptType) return CallDelta();
			else return PutDelta();
		}

		//Modifier functions
		void EuropeanOption::toggle()
		{
			//Toggle option type
			if(OT_CALL == OptType) OptType = OT_PUT;
			else OptType = OT_CALL;
		}
	}
}
