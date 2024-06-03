// ========= Download Function ==========
function downlaod() {

  // Show alert after form submission
  alert("Game is Downloaded!");
}

// ========= Slideshow Function ==========
// Next/previous controls
function plusSlides(n, carouselId) {
  showSlides((slideIndex[carouselId] += n), carouselId);
}

// Thumbnail image controls
function currentSlide(n, carouselId) {
  showSlides((slideIndex[carouselId] = n), carouselId);
}

function showSlides(n, carouselId) {
  let i;
  let slides = document.querySelectorAll(`#${carouselId} .carousel-item`);

  if (n >= slides.length) {
    slideIndex[carouselId] = 0;
  }
  if (n < 0) {
    slideIndex[carouselId] = slides.length - 1;
  }

  for (i = 0; i < slides.length; i++) {
    slides[i].style.display = "none";
  }

  slides[slideIndex[carouselId]].style.display = "block";
}

// Initialize slides for each carousel
let slideIndex = {};

// Initialize S-Class carousel
slideIndex["s-class-carousel"] = 0;
showSlides(slideIndex["s-class-carousel"], "s-class-carousel");

// Initialize A-Class carousel
slideIndex["a-class-carousel"] = 0;
showSlides(slideIndex["a-class-carousel"], "a-class-carousel");

// Initialize S-Class carousel
slideIndex["b-class-carousel"] = 0;
showSlides(slideIndex["b-class-carousel"], "b-class-carousel");

// Initialize A-Class carousel
slideIndex["c-class-carousel"] = 0;
showSlides(slideIndex["c-class-carousel"], "c-class-carousel");

// Initialize S-Class carousel
slideIndex["d-class-carousel"] = 0;
showSlides(slideIndex["d-class-carousel"], "d-class-carousel");

// ========= Readtime Function ==========

// ========= See More Function ==========
function toggleDescription() {
  const fullDescription = document.querySelector(".full-description");
  const seeMoreBtn = document.querySelector(".see-more-btn");
  if (fullDescription.style.display === "none") {
    fullDescription.style.display = "block";
    seeMoreBtn.textContent = "See less";
  } else {
    fullDescription.style.display = "none";
    seeMoreBtn.textContent = "See more";
  }
}

// ========= Form validation ==========
function validateForm() {
  // Fetching input values
  var name = document.getElementById("inputName").value;
  var email = document.getElementById("inputEmail").value;
  var password = document.getElementById("inputPassword").value;
  var dob = document.getElementById("inputDob").value;
  var gender = document.getElementById("genderSelect").value;
  var role = document.getElementById("roleSelect").value;
  var agreeTerms = document.getElementById("agreeTerms").checked;

  // Resetting error messages
  document.getElementById("nameError").textContent = "";
  document.getElementById("emailError").textContent = "";
  document.getElementById("passwordError").textContent = "";
  document.getElementById("dobError").textContent = "";
  document.getElementById("termsError").textContent = "";

  // Validation for Name
  if (name === "") {
    document.getElementById("nameError").textContent = "Name is required";
    return false;
  }

  // Validation for Email
  if (email === "") {
    document.getElementById("emailError").textContent = "Email is required";
    return false;
  }

  // Validation for Password
  if (password === "") {
    document.getElementById("passwordError").textContent =
      "Password is required";
    return false;
  }

  if (password.length < 6) {
    document.getElementById("passwordError").textContent =
      "Password must be at least 6 characters";
    return false;
  }

  // Validation for Date of Birth
  if (dob === "") {
    document.getElementById("dobError").textContent =
      "Date of Birth is required";
    return false;
  }

  // Validation for Gender
  if (gender === "") {
    alert("Please select a gender");
    return false;
  }

  // Validation for Role
  if (role === "") {
    alert("Please select a role");
    return false;
  }

  // Validation for Terms and Conditions agreement
  if (!agreeTerms) {
    document.getElementById("termsError").textContent =
      "Please agree to the terms and conditions";
    return false;
  }

  // If all validations pass, allow the form to submit
  return true;
}

function subscribe() {
  // Validate form here if needed
  if (!validateForm()) {
    return; // Stop the function if validation fails
  }

  // Show alert after form submission
  alert("You subscribed!");
}
