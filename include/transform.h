
#pragma once
#include <Eigen/Core>
#include <Eigen/Dense>
#include <Eigen/StdVector>
#include <iostream>

namespace robot
{

using Transform2d = Eigen::Transform<double, 2, Eigen::Isometry>;
using Translation2d = Eigen::Translation2d;
using Rotation2d = Eigen::Rotation2Dd;
} // namespace robot