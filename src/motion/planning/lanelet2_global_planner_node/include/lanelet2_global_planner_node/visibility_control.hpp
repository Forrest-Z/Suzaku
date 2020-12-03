// Copyright 2019 the Autoware Foundation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Co-developed by Tier IV, Inc. and Apex.AI, Inc.

#ifndef LANELET2_GLOBAL_PLANNER_NODE__VISIBILITY_CONTROL_HPP_
#define LANELET2_GLOBAL_PLANNER_NODE__VISIBILITY_CONTROL_HPP_

#if defined(__WIN32)
  #if defined(LANELET2_GLOBAL_PLANNER_NODE_BUILDING_DLL) || \
  defined(LANELET2_GLOBAL_PLANNER_NODE_EXPORTS)
    #define LANELET2_GLOBAL_PLANNER_NODE_PUBLIC __declspec(dllexport)
    #define LANELET2_GLOBAL_PLANNER_NODE_LOCAL
  #else
    #define LANELET2_GLOBAL_PLANNER_NODE_PUBLIC __declspec(dllimport)
    #define LANELET2_GLOBAL_PLANNER_NODE_LOCAL
  #endif
#elif defined(__linux__)
  #define LANELET2_GLOBAL_PLANNER_NODE_PUBLIC __attribute__((visibility("default")))
  #define LANELET2_GLOBAL_PLANNER_NODE_LOCAL __attribute__((visibility("hidden")))
#elif defined(__APPLE__)
  #define LANELET2_GLOBAL_PLANNER_NODE_PUBLIC __attribute__((visibility("default")))
  #define LANELET2_GLOBAL_PLANNER_NODE_LOCAL __attribute__((visibility("hidden")))
#else
  #error "Unsupported Build Configuration"
#endif
#endif  // LANELET2_GLOBAL_PLANNER__VISIBILITY_CONTROL_HPP_
