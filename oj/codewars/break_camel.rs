fn solution(s: &str) -> String {
    s.chars()
        .flat_map(|c| if c.is_ascii_uppercase() { vec![ ' ', c ] } else { vec![ c ] })
        .collect()
}

// Add your tests here.
// See https://doc.rust-lang.org/stable/rust-by-example/testing/unit_testing.html

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_solution() {
        assert_eq!(solution("camelCasing"), "camel Casing");
        assert_eq!(solution("camelCasingTest"), "camel Casing Test");
    }
}
