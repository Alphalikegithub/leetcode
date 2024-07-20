[TOC]
# Java 开发环境配置和运行代码指南

## 1. 从Git上下载代码后如何运行

### 1.1 设置SDK
- 首先观察本页面右上角的提示，如果有提示的话：
- 根据文件右上角的提示，点击 `setup SDK`，然后选择JDK 8版本（或指向JDK 8的安装目录）。

### 1.2 进入工程结构设置
- 按住快捷键 `Ctrl + Alt + Shift + S` 或者点击左上角 `File` -> `Project Structure` 进入工程结构设置页面。

### 1.3 设置Project选项页
- **Project SDK**: 选择Java 8（选择JDK目录）。
- **Project Language Level**: 设置为8。
- **Project Compiler Output**: 设置一个目录存放编译后的class文件，建议设置为当前工程目录的 `/out`。
  - 例如当前工程目录为 E:/idea_space/35th/java35th；建议out目录设置为 E:/idea_space/35th/java35th/out
- 如此，完成Project选项页的设置，这一步是工程的基本设置，必须要完成。

### 1.4 设置Modules选项页
- 点击页面中间位置的“+”号，选择 `Import Module`。（Module已存在，只是不能识别而已，所以直接导入即可，不要点击New Module）
- 找到并选择需要导入的module文件夹，然后点击 `OK`。
- 在弹出的窗口中选择 `Next` 到底，最后选择 `OK` 关闭设置。如果出现override（覆盖）提示，说明选错了module文件夹，再仔细看一下目录。

### 1.5 测试代码运行
- 完成module导入后，测试代码是否能正常运行，正常运行即为添加成功。

## 2. 包的概念和作用

### 2.1 创建包
- 在IDEA的工程（module）下，右键 `src` 目录 -> `New` -> `Package` 创建包。
- 单级包名直接输入字符串，多级包名用`.`隔开。

### 2.2 包的作用
- 组织Java文件体系，区分分类。
- 同包下不允许有同名Java文件或类。

### 2.3 扩展
- 一个Java文件中，只能有一个public修饰的类，并且该public class的类名必须和Java文件的名字保持一致。但是非public class在一个Java文件中既不限制数量,也不限制名字。
- 一个Java文件中可以有多个class,这些class类都是同包的关系，而同包不允许出现同名类。不管public还是非public,类名在同包下都不能同名。

### 2.4 注释
- 单行注释使用 `//`，多行注释使用 `/* */`。
- 注解与注释不同，注解用 `@` 标识。

## 3. IDEA常用快捷键

- `Ctrl + Z`：撤销操作
- `Alt + Enter`：快速修复编译错误
- `Ctrl + Alt + L`：格式化代码
- `Ctrl + Y`：删除光标所在行
- `Ctrl + D`：复制光标所在行
- `Ctrl + /`：单行注释
- `Ctrl + Shift + /`：多行注释

## 4. 示例代码

### 4.1 HelloWorld 示例

```java
package test;

public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("hello world!");
        int a = 10;
        int b = 20;
        int sum = a + b;
        System.out.println(sum);
    }
}

class A {}
class B {}
class C {}
```

### 4.2 数据类型示例

```java
package com.cskaoyan.javase._0datatype;

public class Demo {
    public static void main(String[] args) {
        char a = 'a';
        char b = 97;
        System.out.println(a);
        System.out.println(b);
        System.out.println(b + 20);

        float f1 = 0.1F;
        float f2 = 0.100000000000001F;
        System.out.println(f1 == f2);
    }
}
```

### 4.3 标识符示例

```java
package com.cskaoyan.javase._1identifier;

public class Demo {
    public static void main(String[] args) {
        int 张三;
        int 好きだ;
        int student;
        int a = 10;
        int b = 20;
        int c = 30;
        int length;
        int l1;
        int l2;
        int l3;
        int len1;
        int len2;
        int len3;
    }
}
```

### 4.4 常量示例

```java
package com.cskaoyan.javase._2const;

public class Demo {
    public static void main(String[] args) {
        int a = 10;
        boolean b = true;
        System.out.println("hello world!");
        String s = null;
    }
}
```

---

# Java 数据类型

## 1. 数据类型的定义

**数据类型**: 表示一组数据的集合，以及基于该数据集合的一组合法操作。它不仅表示一组数据，还限制了这组数据能够执行的操作。

**公式**: 数据类型 = 数据 + 操作

**举例**:
- **int**: 一种基本数据类型，表示一定范围内的整数，并支持加、减、乘、除等操作，但不支持求长度、求宽度等操作。
- **String**: 最常用的引用数据类型，表示字符串，可以进行字符串拼接（`+`）、求长度等操作，但不支持减法、乘法等操作。

## 2. 数据类型的分类

Java 有两种数据类型：
1. **基本数据类型**
2. **引用数据类型**

**基本数据类型**：由 Java 语言默认提供的八种数据类型，JVM 内置设定，所以也称为"内置数据类型"。

**基本数据类型的分类**:
1. **整型**: `byte`, `short`, `int`, `long`
2. **浮点型**: `float`, `double`
    - **优点**: 可以表示非常大和非常小的数
    - **缺点**: 精度有限
3. **字符型**: `char`
    - 通过存储字符的编码值来表示字符。`char` 实际上存储的是一个16位的无符号正整数值，范围是 [0,65535]。编码集使用 Unicode 编码集。
4. **布尔型**: `boolean`
    - 表示真（`true`）和假（`false`），没有其他取值。

**浮点型数据类型的内存使用情况**:
- **float**: 4 字节（32 位），大约 ±3.403E38（有效位数 7-8 位）
- **double**: 8 字节（64 位），大约 ±1.798E308（有效位数 16-17 位）

所有其他数据类型都是 **引用数据类型**。

### 示例代码

```java
package com.cskaoyan.javase._0datatype;

public class Demo {
    public static void main(String[] args) {
        char a = 'a';
        char b = 97;
        System.out.println(a);
        System.out.println(b);
        System.out.println(b + 20);

        float f1 = 0.1F;
        float f2 = 0.100000000000001F;
        System.out.println(f1 == f2);
    }
}
```

## Java 标识符

**标识符**: 表示名字的字符串。需要标识符起名字的结构包括：
1. 类名（包括接口名、注解名等）
2. 方法名（如 `main`）
3. 变量名
4. 包名

**标识符的规则**:
1. 必须以字母（A-Z 和 a-z）、下划线（`_`）、美元符号（`$`）或 Unicode 字符集编号为 0xC0 及其后面的所有符号开头。
2. 可以包含字母、数字（0-9）、美元符号、下划线或 Unicode 字符集编号为 0xC0 及其后面的所有符号。
3. 不能以数字开头。

**Java 数字表示法**:
- **十进制**: 直接写数字（如 `10`）
- **十六进制**: 以 `0x` 开头（如 `0xC0`）
- **二进制**: 以 `0b` 开头（如 `0b1010`）
- **八进制**: 以 `0` 开头（如 `077`）

**命名约定**:
- **驼峰命名法**:
  - **小驼峰**: 第一个单词小写，后续单词首字母大写（如 `myName`，`myFirstJavaProgram`）
  - **大驼峰**: 每个单词

首字母大写（如 `MyName`，`MyFirstJavaProgram`）
- **包名**:
  - 反转的公司域名作为开头（如 `com.baidu.xxx`）
  - 单词全小写
  - 使用单数形式

**最终目标**: "见名知意"。一个好的标识符命名应该能够让人通过名字就知道该标识符的作用。

### 示例代码

```java
package com.cskaoyan.javase._1identifier;

public class Demo {
    public static void main(String[] args) {
        int 张三;
        int 好きだ;
        int student;
        int a = 10;
        int b = 20;
        int c = 30;
        int length;
        int l1;
        int l2;
        int l3;
        int len1;
        int len2;
        int len3;
    }
}
```