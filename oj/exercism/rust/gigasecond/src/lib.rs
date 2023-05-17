use time::{PrimitiveDateTime as DateTime, ext::NumericalDuration};

// Returns a DateTime one billion seconds after start.
pub fn after(start: DateTime) -> DateTime {
    // unimplemented!("What time is a gigasecond later than {start}");
    // start + Duration::new(1_000_000_000, 0)
    start + 1e9.seconds()
}
