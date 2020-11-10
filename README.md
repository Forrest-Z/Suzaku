# 怎么搭建一个自动驾驶操作系统

## 目前我想做的工作
  - 一个良好的可视化模块(正在做的工作，调研了OpenGL以及WebGL, 最后还是选择OpenGL来开发)
  - 一个良好的地图
  - 坐标系，禁止frenet坐标系
  - 地图，禁止各种参数化曲线地图，
  - 一个良好的结构化环境的规划器
    - 路径规划器
    - 速度规划器, 禁止ST图
    - 禁止依赖某种参数化参考线（frenet）
  - 一个良好的非结构化环境的规划器
  - 一个良好的决策器,状态机设计
## 开发规范
  - 代码格式要求： .clang_format
  - 简单的就是最好的
  - 最好避免重复造轮子，利用好开源代码
  - 出现corner case时写上utest
  - 最好测试重要函数的性能
  - 最好利用上日志系统，方便检查。
  - 在一个版本比较稳定的时候，最好打上版本标签(Tag)
  - 最好不要直接在系统里面安装环境，而使用git submodule, 然后利用Cmake链接上。对于需要的依赖，及时补充在Depends目录下
  - 关于代码文档，及时补充上参考资料。

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

## 开发文档
### OpenGL

- https://github.com/LearnOpenGL-CN/LearnOpenGL-CN
- https://blog.csdn.net/xiangzhihong8/article/details/84776943
### WebGL