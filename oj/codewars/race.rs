fn race(v1: i32, v2: i32, g: i32) -> Option<Vec<i32>> {
    if v1 >= v2 {
        None
    } else {
        let d = (3600 * g) / (v2 - v1);
        Some(vec![d / 3600, d / 60 % 60, d % 60])
    }
}

#[test]
fn basic_tests() {
    assert_eq!(race(720, 850, 70), Some(vec![0, 32, 18]));
    assert_eq!(race(80, 100, 40), Some(vec![2, 0, 0]));
    assert_eq!(race(80, 91, 37), Some(vec![3, 21, 49]));
    assert_eq!(race(820, 81, 550), None);
}