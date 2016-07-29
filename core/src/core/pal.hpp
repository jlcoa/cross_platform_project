//
//  pal.hpp
//  core
//
//  Created by Steve Chen on 2/1/16.
//
//

#pragma once

#include "../interface/i_pal_bundle.hpp"

namespace core {
    
    void setPal(std::shared_ptr<core_gen::IPalBundle> pal);
    
    std::shared_ptr<core_gen::IPalBundle> getPal();
}
