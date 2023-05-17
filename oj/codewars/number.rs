fn number(lines: &[&str]) -> Vec<String> {
    lines.iter().enumerate().map(|(l, x)| format!("{}: {}", l+1, x).to_string()).collect()
}

// Add your tests here.
// See https://doc.rust-lang.org/stable/rust-by-example/testing/unit_testing.html

#[cfg(test)]
mod tests {
    use super::number;

    fn dotest(arr: &[&str], expected: &[&str]) {
        let actual = number(arr);
        assert!(actual == expected,
                "With lines= {arr:?}\nExpected {expected:?}\nBut got {actual:?}")
    }

    #[test]
    fn sample_tests() {
        dotest(&[], &[]);
        dotest(&["a", "b", "c"], &["1: a", "2: b", "3: c"]);
        dotest(&["", "", ""], &["1: ", "2: ", "3: "]);
        dotest(&["", "b", "", ""], &["1: ", "2: b", "3: ", "4: "]);
    }
}
