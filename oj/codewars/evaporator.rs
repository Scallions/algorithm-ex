// fn evaporator(content: f64, evap_per_day: i32, threshold: i32) -> i32 {
//     // your code
//     let mut res = content;
//     let mut i = 0;
//     loop {
//         res *= (100 - evap_per_day) as f64 / 100.0;
//         i += 1;
//         if res * 100.0 / content < threshold as f64 {
//             break;
//         }
//     }
//     return i;
// }

fn evaporator(_content: f64, evap_per_day: i32, threshold: i32) -> i32 {
    (f64::from(threshold)/100.0).log(1.0 - f64::from(evap_per_day)/100.0).ceil() as i32
}

#[cfg(test)]
mod tests {
    use super::*;

    fn dotest(_content: f64, evap_per_day: i32, threshold: i32, exp: i32) -> () {
        println!(" evap_per_day: {:?}", evap_per_day);
        println!("threshold: {:?}", threshold);
        let ans = evaporator(_content, evap_per_day, threshold);
        println!(" actual:\n{:?}", ans);
        println!("expect:\n{:?}", exp);
        println!(" {};", ans == exp);
        assert_eq!(ans, exp);
        println!("{};", "-");
    }

    #[test]
    fn basic_tests() {
        dotest(10.0, 10, 10, 22);
        dotest(10.0, 10, 5, 29);

    }
}