#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

// Your complete HTML code as a string
const char* htmlContent = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Sabarivasan</title>
  
  <style>
    body {
      font-family: 'Arial', sans-serif;
      background-color: #0a0a0a;
      color: #fff;
      margin: 0;
      padding: 0;
      line-height: 1.6;
      transition: background-color 0.3s, color 0.3s;
    }
    
    body.light-mode {
      background-color: #f4f4f4;
      color: #333;
    }
    
    /* Container */
    .container {
      width: 90%;
      max-width: 1200px;
      margin: 0 auto;
      padding: 0 20px;
    }
    
    /* Navigation Bar */
    .navbar {
      background: #1a1a1a;
      padding: 10px 0;
      position: sticky;
      top: 0;
      z-index: 1000;
    }
    
    body.light-mode .navbar {
      background: #e0e0e0;
    }
    
    .navbar .container {
      display: flex;
      justify-content: space-between;
      align-items: center;
      flex-wrap: wrap;
    }
    
    .navbar .logo {
      font-size: 1.5rem;
      font-weight: bold;
      color: #00fffc;
    }
    
    body.light-mode .navbar .logo {
      color: #333;
    }
    
    .navbar .nav-links {
      list-style: none;
      display: flex;
      gap: 20px;
      margin: 0;
      padding: 0;
    }
    
    .navbar .nav-links a {
      color: #fff;
      text-decoration: none;
      transition: color 0.3s;
    }
    
    body.light-mode .navbar .nav-links a {
      color: #333;
    }
    
    .navbar .nav-links a:hover {
      color: #00fffc;
    }
    
    body.light-mode .navbar .nav-links a:hover {
      color: #00ccca;
    }
    
    .theme-button {
      background: none;
      border: none;
      font-size: 1.5rem;
      cursor: pointer;
      color: #fff;
    }
    
    body.light-mode .theme-button {
      color: #333;
    }
    
    /* Header */
    .header {
      text-align: center;
      padding: 100px 0;
      background: linear-gradient(45deg, #0a0a0a, #1a1a1a);
    }
    
    body.light-mode .header {
      background: linear-gradient(45deg, #f4f4f4, #e0e0e0);
    }
    
    .header .profile-photo {
      width: 250px;
      height: 250px;
      border-radius: 50%;
      margin-bottom: 20px;
      border: 3px solid #00fffc;
      transition: transform 0.3s;
    }
    
    body.light-mode .header .profile-photo {
      border-color: #00ccca;
    }
    
    .header .profile-photo:hover {
      transform: scale(1.1);
    }
    
    .subtext {
      font-size: 1.2rem;
      margin-top: 10px;
    }
    
    body.light-mode .subtext {
      color: #555;
    }
    
    .button {
      display: inline-block;
      padding: 10px 20px;
      background: #00fffc;
      color: #0a0a0a;
      text-decoration: none;
      border-radius: 5px;
      margin-top: 20px;
      transition: background 0.3s, box-shadow 0.3s;
    }
    
    body.light-mode .button {
      background: #00ccca;
      color: #fff;
    }
    
    .button:hover {
      background: #00ccca;
      box-shadow: 0 0 10px #00fffc;
    }
    
    body.light-mode .button:hover {
      background: #00a8a6;
    }
    
    /* Typing Animation */
    .typing-animation {
      overflow: hidden;
      border-right: 0.15em solid #00fffc;
      white-space: nowrap;
      margin: 0 auto;
      letter-spacing: 0.15em;
      animation: typing 3.5s steps(40, end), blink-caret 0.75s step-end infinite;
    }
    
    body.light-mode .typing-animation {
      border-right-color: #00ccca;
    }
    
    @keyframes typing {
      from { width: 0; }
      to { width: 100%; }
    }
    
    @keyframes blink-caret {
      from, to { border-color: transparent; }
      50% { border-color: #00fffc; }
    }
    
    /* Sections */
    section {
      padding: 60px 0;
      opacity: 0;
      transform: translateY(20px);
      transition: opacity 0.6s ease-out, transform 0.6s ease-out;
    }
    
    section.visible {
      opacity: 1;
      transform: translateY(0);
    }
    
    h2 {
      font-size: 2.5rem;
      margin-bottom: 20px;
      transition: transform 0.3s;
    }
    
    body.light-mode h2 {
      color: #333;
    }
    
    h2:hover {
      transform: scale(1.05);
    }
    
    /* Grid Layout */
    .grid-container {
      display: grid;
      grid-template-columns: repeat(auto-fit, minmax(250px, 1fr));
      gap: 20px;
    }
    
    .grid-item {
      background: #1a1a1a;
      padding: 20px;
      border-radius: 10px;
      transition: transform 0.3s, box-shadow 0.3s;
    }
    
    body.light-mode .grid-item {
      background: #e0e0e0;
      color: #333;
    }
    
    .grid-item:hover {
      transform: scale(1.05);
      box-shadow: 0 0 20px #00fffc;
    }
    
    body.light-mode .grid-item:hover {
      box-shadow: 0 0 20px #00ccca;
    }
    
    /* Contact Links */
    .contact-link {
      color: #00fffc;
      text-decoration: none;
      transition: color 0.3s;
    }
    
    body.light-mode .contact-link {
      color: #00ccca;
    }
    
    .contact-link:hover {
      color: #00ccca;
    }
    
    body.light-mode .contact-link:hover {
      color: #00a8a6;
    }
    
    /* Footer */
    .footer {
      text-align: center;
      padding: 20px 0;
      background: #1a1a1a;
      margin-top: 60px;
    }
    
    body.light-mode .footer {
      background: #e0e0e0;
      color: #333;
    }
    
    /* View Button Styling */
    .view-button {
      display: inline-block;
      padding: 10px 20px;
      background: #00fffc;
      color: #0a0a0a;
      text-decoration: none;
      border-radius: 5px;
      margin-top: 15px;
      transition: background 0.3s, box-shadow 0.3s;
    }
    
    .view-button:hover {
      background: #00ccca;
      box-shadow: 0 0 10px #00fffc;
    }
    
    body.light-mode .view-button {
      background: #00ccca;
      color: #fff;
    }
    
    body.light-mode .view-button:hover {
      background: #00a8a6;
    }
    
    /* Mobile Navigation Toggle */
    .nav-toggle {
      display: none;
      background: none;
      border: none;
      font-size: 1.5rem;
      color: #fff;
      cursor: pointer;
    }
    
    body.light-mode .nav-toggle {
      color: #333;
    }
    
    .highlight {
      color: #00fffc;
    }
    
    body.light-mode .highlight {
      color: #00ccca;
    }
    
    /* Responsive Styles */
    @media (max-width: 768px) {
      .navbar .nav-links {
        flex-direction: column;
        align-items: center;
        gap: 10px;
        display: none;
        width: 100%;
      }
    
      .navbar .nav-links.active {
        display: flex;
      }
    
      .nav-toggle {
        display: block;
      }
    
      .header {
        padding: 60px 0;
      }
    
      .header .profile-photo {
        width: 170px;
        height: 170px;
      }
    
      section {
        padding: 40px 0;
      }
    }
    
    @media (max-width: 480px) {
      .header {
        padding: 40px 0;
      }
    
      .header .profile-photo {
        width: 150px;
        height: 150px;
      }
    
      .grid-container {
        grid-template-columns: 1fr;
      }
    
      section {
        padding: 30px 0;
      }
    }
  </style>
</head>
<body>
  <!-- Navigation Bar -->
  <nav class="navbar">
   <div class="container">
      <div class="logo">Sabarivasan S M</div>
      <button class="nav-toggle">☰</button>
      <ul class="nav-links">
        <li><a href="#about">About</a></li>
        <li><a href="#skills">Skills</a></li>
        <li><a href="#education">Education</a></li>
        <li><a href="#experience">Experience</a></li>
        <li><a href="#projects">Projects</a></li>
        <li><a href="#contact">Contact</a></li>
      </ul>
      <button id="theme-toggle" class="theme-button">🌙</button>
    </div>
  </nav>

  <!-- Header Section -->
  <header class="header">
     <div class="container">
      <div class="header-content">
        <img src="https://avatars.githubusercontent.com/u/144119741?v=4" alt="SabariVasan S.M" class="profile-photo">
        <h1 class="typing-animation">Hi, I'm <span class="highlight">SabariVasan</span></h1>
        <br>
        <h2 style="font-size: 30px;text-align: center;color: #00fffc;">" Mechanical Engineer | Web Developer | Tech Aficionado "</h2>
        <br>
        <br>
        <a href="https://drive.google.com/file/d/1yxyEmJ0BHZORRJSPtC-p0WIjZtV6lOPj/view?usp=sharing" class="button" download>Download Resume</a>
      </div>
    </div>
  </header>

  <section id="about" class="about">
    <div class="container">
      <h2>Career Objective</h2>
      <h2 style="font-size: 30px;text-align: center;color: #00fffc;">" Mechanical Precision, IT Efficiency, Future-Ready Solutions "</h2>
      <p style="font-size: 20px;">A highly motivated and detail-oriented individual with a background in Mechanical Engineering and pursuing advanced studies in Information Technology. I aim to leverage my technical expertise and problem-solving skills to contribute to the integration of IT solutions within engineering environments.</p>
    </div>
  </section>

  <!-- Skills Section -->
  <section id="skills" class="skills">
    <div class="container">
      <h2>Skills</h2>
      <div class="grid-container">
        <div class="grid-item">
          <h3>Languages</h3>
          <p>Python, JavaScript</p>
        </div>
        <div class="grid-item">
          <h3>Front End</h3>
          <p>HTML, CSS, JS</p>
        </div>
        <div class="grid-item">
          <h3>Framework</h3>
          <p>React JS</p>
        </div>
        <div class="grid-item">
          <h3>Back End</h3>
          <p>Node JS</p>
        </div>
        <div class="grid-item">
          <h3>Database</h3>
          <p>SQL, MongoDB</p>
        </div>
        <div class="grid-item">
          <h3>Softwares</h3>
          <p>Auto CAD, Pro-E</p>
        </div>
        <div class="grid-item">
          <h3>Design Tools</h3>
          <p>Miro, Canva, Figma</p>
        </div>
        <div class="grid-item">
          <h3>Devops</h3>
          <p>Jenkins, Docker</p>
        </div>
      </div>
    </div>
  </section>

  <!-- Education Section -->
  <section id="education" class="education">
    <div class="container">
      <h2>Education</h2>
      <div class="grid-container">
        <div class="grid-item">
          <h3>B.Tech - IT</h3>
          <p>Kongu Engineering College</p>
          <p>2025 | 6.49 CGPA</p>
        </div>
        <div class="grid-item">
          <h3>Diploma - Mechanical</h3>
          <p>Sakthi Institute Of Technology</p>
          <p>2023 | 85%</p>
        </div>
        <div class="grid-item">
          <h3>HSLC</h3>
          <p>SVV Hr. Sec. School</p>
          <p>2021 | 85%</p>
        </div>
        <div class="grid-item">
          <h3>SSLC</h3>
          <p>Govt Boys Hr. Sec. School</p>
          <p>2019 | 68%</p>
        </div>
      </div>
    </div>
  </section>

  <!-- Work Experience Section -->
  <section id="experience" class="experience">
    <div class="container">
      <h2>Work Experience</h2>
      <div class="grid-container">
        <div class="grid-item">
          <h3 style="color: #00fffc;">CNC Operator</h3>
          <p>Sakthi Auto Component Limited, Perundurai.</p>
          <p>1 Month [Full Time]</p>
        </div>
        <div class="grid-item">
          <h3 style="color: #00fffc;">Sakthi Sugars</h3>
          <p>Workshop Fitter And Welder</p>
          <p>15 days [Intern]</p>
        </div>
      </div>
    </div>
  </section>

  <!-- Projects Section -->
  <section id="projects" class="projects">
    <div class="container">
      <h2>Projects</h2>
      <div class="grid-container">
        <div class="grid-item">
          <h3>E-learning Platform</h3>
          <p>The Interactive Programming Learning Platform is designed to help students learn and practice programming languages and run their code in real-time without needing to set up complex development environments.</p>
          <a href="https://github.com/Sabari-Vasan-SM/E-learning-Platform" class="view-button">View</a>
        </div>
        <div class="grid-item">
          <h3>G Code Simulator</h3>
          <p>A web-based platform designed to assist users, particularly in the field of CNC machining and 3D printing, by running G-codes providing real-time visual feedback helping to identify potential issues before actual execution on physical machinery.</p>
          <a href="https://github.com/Sabari-Vasan-SM/CNC-G-code-Simulator-With-Live-Simulation" class="view-button">View</a>
        </div>
        <div class="grid-item">
          <h3>Admission Management</h3>
          <p>The Admission Management System is a web platform that streamlines school and college admissions. Students can create accounts, upload marks, and select courses, while admins review applications and select candidates.</p>
          <a href="https://github.com/Sabari-Vasan-SM/Admisssion-management" class="view-button">View</a>
        </div>
        <div class="grid-item">
          <h3>CartZY</h3>
          <p>CartZY is a user-friendly e-commerce app designed to make online shopping simple and enjoyable. Browse a wide range of products, from electronics to accessories, and easily add them to your cart.</p>
          <a href="https://github.com/Sabari-Vasan-SM/CartZY" class="view-button">View</a>
        </div>
        <div class="grid-item">
          <h3>Secure Pass</h3>
          <p>SecurePass is a React-based password manager that allows users to register and log in securely. Once logged in, users can store, manage, and retrieve their passwords effortlessly.</p>
          <a href="https://github.com/Sabari-Vasan-SM/Secure-Pass" class="view-button">View</a>
        </div>
      </div>
    </div>
  </section>

  <!-- Interests Section -->
  <section id="interests" class="interests">
    <div class="container">
      <h2>Area of Interest</h2>
      <div class="grid-container">
        <div class="grid-item">
          <h3>Web Development</h3>
        </div>
        <div class="grid-item">
          <h3>Cloud Computing</h3>
        </div>
        <div class="grid-item">
          <h3>Mechanical Engineering Integration with IT</h3>
        </div>
      </div>
    </div>
  </section>

  <!-- Contact Section -->
  <section id="contact" class="contact">
    <div class="container">
      <h2>Contact</h2>
      <div class="grid-container">
        <div class="grid-item">
          <h3>Phone</h3>
          <a href="tel:9677465071" class="contact-link">9677465071</a>
        </div>
        <div class="grid-item">
          <h3>Email</h3>
          <a href="mailto:sabarivasan1239@gmail.com" class="contact-link">sabarivasan1239@gmail.com</a>
        </div>
        <div class="grid-item">
          <h3>Location</h3>
          <p>Kavindapadi, Erode, Tamil Nadu</p>
        </div>
        <div class="grid-item">
          <h3>GitHub</h3>
          <a href="https://github.com/Sabari-Vasan-SM" target="_blank" class="contact-link">GitHub Profile</a>
        </div>
        <div class="grid-item">
          <h3>LinkedIn</h3>
          <a href="https://www.linkedin.com/in/sabarivasan-s-m-b10229255/" target="_blank" class="contact-link">LinkedIn Profile</a>
        </div>
      </div>
    </div>
  </section>

  <!-- Footer -->
  <footer class="footer">
    <div class="container">
      <p>&copy; 2023 SabariVasan S.M. All rights reserved.</p>
    </div>
  </footer>

  <script>
    const themeToggle = document.getElementById("theme-toggle");
    const body = document.body;

    themeToggle.addEventListener("click", () => {
      body.classList.toggle("light-mode");
      themeToggle.textContent = body.classList.contains("light-mode") ? "🌙" : "☀️";
      
      // Save preference to localStorage
      localStorage.setItem('theme', body.classList.contains("light-mode") ? 'light' : 'dark');
    });

    // Check for saved theme preference
    if (localStorage.getItem('theme') === 'light') {
      body.classList.add('light-mode');
      themeToggle.textContent = "🌙";
    }

    // Scroll Animations
    const sections = document.querySelectorAll("section");

    const observer = new IntersectionObserver(
      (entries) => {
        entries.forEach((entry) => {
          if (entry.isIntersecting) {
            entry.target.classList.add("visible");
          }
        });
      },
      { threshold: 0.1 }
    );

    sections.forEach((section) => observer.observe(section));

    // Mobile Navigation Toggle
    const navToggle = document.querySelector(".nav-toggle");
    const navLinks = document.querySelector(".navbar .nav-links");

    navToggle.addEventListener("click", () => {
      navLinks.classList.toggle("active");
    });

    // Close mobile menu when clicking a link
    document.querySelectorAll('.nav-links a').forEach(link => {
      link.addEventListener('click', () => {
        navLinks.classList.remove('active');
      });
    });

  </script>
</body>
</html>
)rawliteral";

void handleRoot() {
  server.send(200, "text/html", htmlContent);
}

void setup() {
  Serial.begin(115200);

  // Start the ESP8266 in Access Point mode with custom SSID and password
  WiFi.softAP(" ESP32_Hotspot (192.168.4.1)", "12345678");

  // Print the IP address assigned to the access point
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Access Point IP: ");
  Serial.println(IP);  // Typically 192.168.4.1

  // Define route
  server.on("/", handleRoot);

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
