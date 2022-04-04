


fn main() {
    // 不可变长度
    // 初始化
    let a: [i32; 5] = [1; 5];
    let a: [i32; 5] = [1, 2, 3, 4, 5];
    // 长度
    println!("{}", a.len());
    // 索引
    println!("{}", a[0]);
    println!("{:?}", a.get(100));
    // 切片
    println!("{:?}", &a[0..2]);
    // 转vec
    println!("{:?}", a.to_vec());

    // 可变长度
    // 初始化
    let mut v: Vec<i32> = Vec::new();
    let mut v: Vec<i32> = vec![1, 2, 3, 4, 5];
    // 长度
    println!("{}", v.len());
    // 索引
    println!("{}", v[0]);
    println!("{:?}", v.get(100));
    // 增删改查
    v.push(6);
    println!("{:?}", v.pop());
    v[3] = 100;
    // 遍历
    for i in &v { // 控制权限
        println!("{}", i);
    }

    for i in &mut v {
        *i += 1;
    }

    for i in v.iter() {
        println!("{}", i);
    }

    v.iter().map(|x| println!("{}", x));
}