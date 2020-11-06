# 怎么搭建一个自动驾驶操作系统

- 目前我想做的工作
  - 一个良好的可视化模块
  - 一个良好的地图
  - 坐标系，禁止frenet坐标系
  - 地图，禁止各种参数化曲线地图，
  - 一个良好的结构化环境的规划器
    - 路径规划器
    - 速度规划器, 禁止ST图
    - 禁止依赖某种参数化参考线（frenet）
  - 一个良好的非结构化环境的规划器
  - 一个良好的决策器,状态机设计
- 开发规范
  - 代码格式要求： .clang_format

## Depends

- openCV
- openGL
- Eigen
- Googletest
- Google Benchmark
- box2d
- lanelet2
- GLFW
- Open DDS
- Ubuntu 18.04
- Cmake 3.5.1(at least)

## OPENGL 教程

- https://github.com/LearnOpenGL-CN/LearnOpenGL-CN
- https://blog.csdn.net/xiangzhihong8/article/details/84776943
