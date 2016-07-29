//
//  pal.cpp
//  core
//
//  Created by Steve Chen on 2/1/16.
//
//

#include "pal.hpp"

namespace core {
    
    static std::shared_ptr<core_gen::IPalBundle> gPalBundle;
    
    std::shared_ptr<core_gen::IPalBundle> getPal() {
        return gPalBundle;
    }
    
    void setPal(std::shared_ptr<core_gen::IPalBundle> pal) {
        gPalBundle = pal;
    }
    
}