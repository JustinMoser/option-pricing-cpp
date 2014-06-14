//static class for distrubitions
//Currently: Gaussian and Cumulative
namespace Math
{
	namespace Statistics
	{
		class Distribution
		{
			public:
				//PI
				static const long double PI;

			public:
				static double n(double x);	//Gaussian distribution function
				static double N(double x);	//Cumulative normal distribution function
		};
	}
}
