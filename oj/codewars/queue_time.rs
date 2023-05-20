fn queue_time(customers: &[u32], n: u32) -> u32 {
    let mut q: Vec<u32> = vec![0; n as usize];
    customers.iter().for_each(|&x| {
        *q.iter_mut().min().unwrap() += x;
    });
    *q.iter().max().unwrap()
}

// Add your tests here.
// See https://doc.rust-lang.org/stable/rust-by-example/testing/unit_testing.html

#[cfg(test)]
mod tests {
    use super::queue_time;

    fn dotest(c: &[u32], n: u32, expected: u32) {
        let actual = queue_time(c, n);
        assert!(actual == expected, "With customers = {c:?}, n = {n}\nExpected {expected} but got {actual}")
    }

    #[test]
    fn fixed_tests() {
        dotest(&[], 1, 0);
        dotest(&[5], 1, 5);
        dotest(&[2], 5, 2);
        dotest(&[1, 2, 3, 4, 5], 1, 15);
        dotest(&[1, 2, 3, 4, 5], 100, 5);
        dotest(&[2, 2, 3, 3, 4, 4], 2, 9);
    }
}