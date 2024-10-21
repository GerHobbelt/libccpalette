
#pragma once

#include <ccpalette/ccpalette.h>

#include <stdint.h>
#include <vector>

// internally, we store color palette elements (i.e. single colors) in a 3+alpha+type general storage container:

namespace ccpalette {
	namespace internal {

		template<typename T>
		struct TColor {
			T v[3];
			float alpha;
		};

		// instantiate template:

		typedef TColor<int> iColor;
		typedef TColor<float> fColor;

		// the generic storage container that forms the basis of a color palette:

		union ColorUnit {
				iColor i;
				fColor f;
		};

		struct ColorPalette {
			unsigned int count;
			int type_id;
			bool has_alpha;

			std::vector<ColorUnit> palette;
		};
	}
}

