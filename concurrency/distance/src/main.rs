extern crate rand;
use std::thread;

use std::fmt;

static number_of_points: isize = 10;

// Define 'Point' Structure
#[derive(Copy, Clone)]
struct Point {
    x: f64,
    y: f64
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

fn closest(list: &[Point]) -> Option<(Point, Point, f64)> {
    //ref mut nearest = &list[0];
    let mut shortest = (Point::new(0.0, 0.0), Point::new(0.0, 0.0), std::f64::MAX);

    for point in &list[1..list.len()] {
        let distance = ((list[0].x - point.x) * (list[0].x - point.x)
         + (list[0].y - point.y) * (list[0].y - point.y)).sqrt();
        if distance < shortest.2 {
            shortest = (list[0], *point, distance);
        }
    }
    if shortest.2 == std::f64::MAX { None } else { Some(shortest) }
}

// Main thread
fn main() {
    // Define mutable vector for 'Point's
    let mut points: Vec<Point> = Vec::new();

    // Populate 'points' vector with 'number_of_points' random 'Point's
    for i in 0..number_of_points {
        points.push(Point::new(rand::random::<f64>(), rand::random::<f64>()));
    }

    for i in 0..points.len() {
        // Claculate the distance between the current 'Point' and the rest

            match closest(&points[i..points.len()]) {
                None => {},
                Some(v) => println!("| {} - {} | = {}", v.0, v.1, v.2)
            }
    }

}