fn get_char(c: i32) -> char {
    char::try_from(u32::try_from(c).expect("Not a valid ASCII code")).expect("Not a valid ASCII code")
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(get_char(55), '7');
        assert_eq!(get_char(56), '8');
        assert_eq!(get_char(57), '9');
        assert_eq!(get_char(58), ':');
        assert_eq!(get_char(59), ';');
        assert_eq!(get_char(60), '<');
        assert_eq!(get_char(61), '=');
        assert_eq!(get_char(62), '>');
        assert_eq!(get_char(63), '?');
        assert_eq!(get_char(64), '@');
        assert_eq!(get_char(65), 'A');
    }
}