
-- ===========================
-- Practice DB: shop_practice
-- MySQL 8+ compatible
-- ===========================
DROP DATABASE IF EXISTS shop_practice;
CREATE DATABASE shop_practice;
USE shop_practice;

-- ---------- Customers ----------
CREATE TABLE customers (
  customer_id INT PRIMARY KEY AUTO_INCREMENT,
  first_name VARCHAR(50) NOT NULL,
  last_name  VARCHAR(50) NOT NULL,
  email      VARCHAR(100) NOT NULL UNIQUE,
  phone      VARCHAR(20),
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- ---------- Addresses ----------
CREATE TABLE addresses (
  address_id INT PRIMARY KEY AUTO_INCREMENT,
  customer_id INT NOT NULL,
  line1 VARCHAR(100) NOT NULL,
  line2 VARCHAR(100),
  city  VARCHAR(50) NOT NULL,
  state VARCHAR(50),
  country VARCHAR(50) DEFAULT 'India',
  postal_code VARCHAR(20),
  is_default TINYINT(1) DEFAULT 0,
  FOREIGN KEY (customer_id) REFERENCES customers(customer_id) ON DELETE CASCADE
);

-- ---------- Categories ----------
CREATE TABLE categories (
  category_id INT PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR(50) NOT NULL UNIQUE
);

-- ---------- Products ----------
CREATE TABLE products (
  product_id INT PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR(100) NOT NULL,
  category_id INT NOT NULL,
  price DECIMAL(10,2) NOT NULL,
  active TINYINT(1) DEFAULT 1,
  created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
  FOREIGN KEY (category_id) REFERENCES categories(category_id) ON DELETE RESTRICT
);

-- ---------- Inventory ----------
CREATE TABLE inventory (
  product_id INT PRIMARY KEY,
  quantity INT NOT NULL DEFAULT 0,
  FOREIGN KEY (product_id) REFERENCES products(product_id) ON DELETE CASCADE
);

-- ---------- Orders ----------
CREATE TABLE orders (
  order_id INT PRIMARY KEY AUTO_INCREMENT,
  customer_id INT NOT NULL,
  order_date DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
  status ENUM('PLACED','PAID','SHIPPED','DELIVERED','CANCELLED') NOT NULL DEFAULT 'PLACED',
  shipping_address_id INT,
  FOREIGN KEY (customer_id) REFERENCES customers(customer_id) ON DELETE RESTRICT,
  FOREIGN KEY (shipping_address_id) REFERENCES addresses(address_id) ON DELETE SET NULL
);

-- ---------- Order Items ----------
CREATE TABLE order_items (
  order_item_id INT PRIMARY KEY AUTO_INCREMENT,
  order_id INT NOT NULL,
  product_id INT NOT NULL,
  quantity INT NOT NULL,
  unit_price DECIMAL(10,2) NOT NULL,
  FOREIGN KEY (order_id) REFERENCES orders(order_id) ON DELETE CASCADE,
  FOREIGN KEY (product_id) REFERENCES products(product_id) ON DELETE RESTRICT,
  UNIQUE KEY uq_order_product (order_id, product_id)
);

-- ---------- Payments ----------
CREATE TABLE payments (
  payment_id INT PRIMARY KEY AUTO_INCREMENT,
  order_id INT NOT NULL UNIQUE,
  amount DECIMAL(10,2) NOT NULL,
  method ENUM('CARD','UPI','NETBANKING','COD') NOT NULL,
  paid_at DATETIME,
  FOREIGN KEY (order_id) REFERENCES orders(order_id) ON DELETE CASCADE
);

-- ---------- Shippers ----------
CREATE TABLE shippers (
  shipper_id INT PRIMARY KEY AUTO_INCREMENT,
  name VARCHAR(100) NOT NULL UNIQUE
);

-- ---------- Shipments ----------
CREATE TABLE shipments (
  shipment_id INT PRIMARY KEY AUTO_INCREMENT,
  order_id INT NOT NULL UNIQUE,
  shipper_id INT NOT NULL,
  shipped_at DATETIME,
  delivered_at DATETIME,
  tracking_number VARCHAR(50) UNIQUE,
  FOREIGN KEY (order_id) REFERENCES orders(order_id) ON DELETE CASCADE,
  FOREIGN KEY (shipper_id) REFERENCES shippers(shipper_id) ON DELETE RESTRICT
);

-- ---------- Reviews ----------
CREATE TABLE reviews (
  review_id INT PRIMARY KEY AUTO_INCREMENT,
  product_id INT NOT NULL,
  customer_id INT NOT NULL,
  rating TINYINT NOT NULL,
  review_text VARCHAR(255),
  created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
  FOREIGN KEY (product_id) REFERENCES products(product_id) ON DELETE CASCADE,
  FOREIGN KEY (customer_id) REFERENCES customers(customer_id) ON DELETE CASCADE
);

-- ---------- Seed Data ----------
INSERT INTO customers (first_name,last_name,email,phone) VALUES
('Aarav','Mehta','aarav@example.com','9000000001'),
('Diya','Sharma','diya@example.com','9000000002'),
('Kabir','Patel','kabir@example.com','9000000003'),
('Isha','Kapoor','isha@example.com','9000000004');

INSERT INTO addresses (customer_id,line1,city,state,country,postal_code,is_default) VALUES
(1,'221B Baker St','Mumbai','MH','India','400001',1),
(1,'Plot 45 MG Road','Pune','MH','India','411001',0),
(2,'12 Residency Rd','Bengaluru','KA','India','560001',1),
(3,'56 Park Street','Kolkata','WB','India','700016',1),
(4,'81 GT Road','Delhi','DL','India','110001',1);

INSERT INTO categories (name) VALUES ('Electronics'),('Books'),('Fashion'),('Home');

INSERT INTO products (name,category_id,price) VALUES
('Wireless Mouse',1,799.00),
('Noise Cancelling Headphones',1,4999.00),
('JavaScript: The Good Parts',2,999.00),
('Dystopian Novel',2,499.00),
('Men T-Shirt',3,699.00),
('Women Sneakers',3,2199.00),
('Coffee Maker',4,3499.00),
('LED Desk Lamp',4,1299.00);

INSERT INTO inventory (product_id,quantity) VALUES
(1,50),(2,20),(3,35),(4,40),(5,60),(6,15),(7,10),(8,25);

INSERT INTO orders (customer_id, order_date, status, shipping_address_id) VALUES
(1,'2025-08-01 10:00:00','PAID',1),
(1,'2025-08-05 12:30:00','DELIVERED',2),
(2,'2025-08-10 09:15:00','SHIPPED',3),
(3,'2025-08-12 14:20:00','PLACED',4),
(4,'2025-08-15 16:00:00','CANCELLED',5);

INSERT INTO order_items (order_id, product_id, quantity, unit_price) VALUES
(1,1,2,799.00),
(1,3,1,999.00),
(2,2,1,4999.00),
(2,5,3,699.00),
(3,6,1,2199.00),
(3,8,2,1299.00),
(4,7,1,3499.00);

INSERT INTO payments (order_id, amount, method, paid_at) VALUES
(1, 2*799.00 + 999.00, 'UPI', '2025-08-01 10:05:00'),
(2, 4999.00 + 3*699.00, 'CARD', '2025-08-05 12:35:00'),
(3, 2199.00 + 2*1299.00, 'NETBANKING', '2025-08-10 09:20:00');

INSERT INTO shippers (name) VALUES ('Blue Dart'),('Delhivery');

INSERT INTO shipments (order_id, shipper_id, shipped_at, delivered_at, tracking_number) VALUES
(2,1,'2025-08-05 13:00:00','2025-08-07 18:00:00','BD123456'),
(3,2,'2025-08-10 20:00:00',NULL,'DL987654');

INSERT INTO reviews (product_id, customer_id, rating, review_text, created_at) VALUES
(1,1,5,'Great mouse!','2025-08-02 11:00:00'),
(2,1,4,'Good sound','2025-08-08 09:00:00'),
(3,2,5,'Must read','2025-08-11 10:00:00'),
(5,2,3,'Okay quality','2025-08-06 13:00:00'),
(6,3,4,'Comfortable shoes','2025-08-12 15:00:00');

-- Helpful indexes for practice
CREATE INDEX idx_orders_customer ON orders(customer_id, order_date);
CREATE INDEX idx_order_items_prod ON order_items(product_id);
CREATE INDEX idx_products_category ON products(category_id);
