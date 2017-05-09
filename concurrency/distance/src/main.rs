extern crate rand;

use std::fmt;
use rand::Rng;

// Define 'Point' Structure
struct Point {
    x: f64,
    y: f64,
}

// Implement 'new' method for 'Point' struct
impl Point {
    fn new(nx: f64, ny: f64) -> Point {
        Point {
            x: nx,
            y: ny
        }
    }
}

// Implement display trait for 'Point' Struct
impl fmt::Display for Point {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "({}, {})", self.x, self.y)
    }
}

fn closest(list: &[Point]) -> f64 {
    //ref mut nearest = &list[0];
    let mut shortest = std::f64::MAX;

    for point in &list[1..list.len()] {
        let distancesqured = (list[0].x - point.x) * (list[0].x - point.x)
         + (list[0].y - point.y) * (list[0].y - point.y);
        if distancesqured < shortest {
            shortest = distancesqured;
            //nearest = &point;
        }
    }
    shortest
}

// Main thread
fn main() {
    // Define mutable vector for 'Point's
    let mut points: Vec<Point> = Vec::new();

    // Populate 'points' vector with 10 random 'Point's
    for i in 0..10 {
        points.push(Point::new(rand::random::<f64>(), rand::random::<f64>()));
    }

    for i in 0..points.len() {
        // Claculate the distance between the current 'Point' and the rest
        let closer = closest(&points[i..points.len()]);
        println!("{}", closer);
    }

    for point in &points {
        println!("{}", point);
    }
}