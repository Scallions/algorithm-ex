

// 初始化
let arr: number[] = [1,2,3,4,5];
let arr1 = new Array(4);
// 长度
console.log(arr.length);

// 增删改查
arr.push(6);
console.log(arr);
arr.pop();
console.log(arr);
arr[0] = 0;
console.log(arr);

// 遍历
for (let i = 0; i < arr.length; i++) {
    console.log(arr[i]);
}

for (const item of arr) {
    console.log(item);
}

for (const item in arr) {
    console.log(item);
}

arr.forEach(function (v){
    console.log(v);
});