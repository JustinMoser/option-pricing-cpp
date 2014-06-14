#include "OptionType.h"

using namespace Instruments::Options;

namespace Instruments
{
	namespace Options
	{
		class EuropeanOption 
		{

			public:
				//Constructors
				
				//Default call option
				EuropeanOption();

				//Field injection constructor
				EuropeanOption( double assetPrice, 
								double strikePrice, 
								double timeToExpiry, 
								double volatility, 
								double riskFreeRate,
								double dividendYield,
								double costOfCarry,
								OptionType optionType);

				//Functions that calculate the option price and (some) sensitivites
				double Price() const;
				double Delta() const;

				//Modifier functions
				void toggle();
		
			//This is a class for calculating the price and delta of a European stock option
			//Using discrete values for equation variables
			//Can only be exercised at T (maturity)
			private:
				double d1;
				double d2;
				double tmp;
				double r; 		//Risk-free interest rate;
				double sig; 	//Volatility
				double T;		//Expiry Date
				double U;		//Current price of underlying asset
				double K; 		//Strike Price
				double b;		//Cost of carry
				double q;		//dividend yield
				OptionType OptType;		
				//Option type (call, put)
				
				//Initialize all default values
				void init();
				void copy(const EuropeanOption& o2);	//Copy one option data to another

				//'Kernel methods' for option calculations
				double CallPrice() const;
				double PutPrice() const;
				double CallDelta() const;
				double PutDelta() const;
		};
	}
}
