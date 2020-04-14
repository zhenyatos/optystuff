#include "UniOpt.h"

class DihUniOpt : public UniOpt
{
public:
	Result optimize(std::function<double(double)> fun, double prec, double a, double b) override;
};