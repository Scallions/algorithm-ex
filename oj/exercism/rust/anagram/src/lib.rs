use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    let wl = word.to_lowercase();
    let mut b: Vec<char> = wl.chars().collect::<Vec<_>>();
    b.sort_unstable();
    possible_anagrams.iter().filter(|x| {
        let pl = x.to_lowercase();
        let mut c: Vec<char> = pl.chars().collect::<Vec<_>>();
        c.sort_unstable();
        c == b && wl != pl
    }).map(|&x| x).collect()
}