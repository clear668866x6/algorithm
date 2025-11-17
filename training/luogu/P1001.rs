#![allow(dead_code, unused_imports, unused_variables, unused_must_use)]
use std::io::{self, Write, BufWriter, Read};
use std::collections::*;
use io_util::FastInput;

fn solve(sc: &mut FastInput, out: &mut BufWriter<io::StdoutLock>) {

}

fn main() {
    let mut input_string = String::new();
    io::stdin().read_to_string(&mut input_string).unwrap();
    
    let mut sc = FastInput::new(&input_string);
    
    let stdout = io::stdout();
    let mut out = BufWriter::new(stdout.lock());
    
    let t = 1;
    for _ in 0..t {
        solve(&mut sc, &mut out);
    }
}

mod io_util {
    use super::*;
    
    pub struct FastInput<'a> {
        iter: std::str::SplitWhitespace<'a>,
    }

    impl<'a> FastInput<'a> {
        pub fn new(s: &'a str) -> Self {
            Self {
                iter: s.split_whitespace(),
            }
        }

        pub fn read<T: std::str::FromStr>(&mut self) -> T {
            self.iter.next().unwrap().parse().ok().unwrap()
        }

        pub fn i32(&mut self) -> i32 { self.read() }
        pub fn i64(&mut self) -> i64 { self.read() }
        pub fn usize(&mut self) -> usize { self.read() }
        pub fn u32(&mut self) -> u32 { self.read() }
        pub fn u64(&mut self) -> u64 { self.read() }
        pub fn f64(&mut self) -> f64 { self.read() }
        pub fn string(&mut self) -> String { self.read() }

        pub fn bytes(&mut self) -> Vec<u8> {
            self.iter.next().unwrap().bytes().collect()
        }

        pub fn chars(&mut self) -> Vec<char> {
            self.iter.next().unwrap().chars().collect()
        }

        pub fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
            (0..n).map(|_| self.read()).collect()
        }

        pub fn tuple2<T: std::str::FromStr, U: std::str::FromStr>(&mut self) -> (T, U) {
            (self.read(), self.read())
        }

        pub fn tuple3<T: std::str::FromStr, U: std::str::FromStr, V: std::str::FromStr>(&mut self) -> (T, U, V) {
            (self.read(), self.read(), self.read())
        }
    }
}