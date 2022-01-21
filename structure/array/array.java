/*
 * @Author       : Scallions
 * @Date         : 2022-01-21 12:32:38
 * @LastEditors  : Scallions
 * @LastEditTime : 2022-01-21 13:09:53
 * @FilePath     : /algorithm-ex/structure/array/array.java
 * @Description  : Java中array的一些东西
 * 资料：
 * https://www.runoob.com/java/java-collections.html
 */
package array;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;

public class array {
    public static void main(String[] args) {
        // #1
        int[] arr1 = new int[3]; // 默认初始化为0
        int[] arr2 = {3, 2, 1}; // 赋值初始化
        int len1 = arr2.length; // 获取长度
        // 增删改查
        // 此种方式不能增加，删除，固定长度
        arr1[0] = 2;
        System.out.println(arr1[0]);
        // 遍历
        // for each
        for(int i: arr2){
            System.out.println(i);
        }
        // for idx
        for(int i=0; i<len1; ++i){
            System.out.println(arr1[i]);
        }
        // Arrays 提供一些常用的函数
        System.out.println(Arrays.binarySearch(arr2, 2));
        Arrays.fill(arr1, 1);
        for(int i: arr1){
            System.out.println(i);
        }
        Arrays.sort(arr2);
        for(int i: arr2){
            System.out.println(i);
        }

        // #2 JDK类
        // 面向接口编程多用接口而不用具体的类
        List<Integer> arr3 = new ArrayList<>();
        List<Integer> arr4 = new ArrayList<>(3);
        // 还有一个从Collection进行初始化的构造函数
        // 增删改查
        arr3.add(3);
        arr3.add(2);
        arr3.add(1);
        arr3.add(4);
        arr3.remove(3);
        arr3.set(0, 4);
        System.out.println(arr3.get(0));
        // 遍历
        // 1. for each
        for(Integer i: arr3){
            System.out.println(i);
        }
        // 2. toArray
        Integer[] arrTmp = new Integer[arr3.size()];
        arr3.toArray(arrTmp);
        for(int i=0; i<arrTmp.length; ++i){
            System.out.println(arrTmp[i]);
        }
        // 3. 迭代器
        Iterator<Integer> ite = arr3.iterator();
        while(ite.hasNext()){
            System.out.println(ite.next());
        }

        // Coleections提供了一些api
        Collections.sort(arr3);
        for(Integer i: arr3){
            System.out.println(i);
        }
    }
}
