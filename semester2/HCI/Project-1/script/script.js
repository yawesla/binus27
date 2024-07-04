// ========= Download Function ==========
function downlaod() {
  // Show alert after form submission
  alert("Game is Downloaded!");
}

// Slideshow Function
let slideIndex = {};

function plusSlides(n, carouselId) {
  showSlides(slideIndex[carouselId] += n, carouselId);
}

function currentSlide(n, carouselId) {
  showSlides(slideIndex[carouselId] = n, carouselId);
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

document.addEventListener("DOMContentLoaded", function () {
  initializeSlides("s-class-carousel");
  initializeSlides("a-class-carousel");
  initializeSlides("b-class-carousel");
  initializeSlides("c-class-carousel");
  initializeSlides("d-class-carousel");
});

function initializeSlides(carouselId) {
  slideIndex[carouselId] = 0;
  showSlides(0, carouselId);
}

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

  document.getElementById("nameError").textContent = "";
  document.getElementById("emailError").textContent = "";
  document.getElementById("passwordError").textContent = "";
  document.getElementById("dobError").textContent = "";
  document.getElementById("termsError").textContent = "";

  if (name === "") {
    document.getElementById("nameError").textContent = "Name is required";
    return false;
  }

  if (email === "") {
    document.getElementById("emailError").textContent = "Email is required";
    return false;
  }

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

  if (dob === "") {
    document.getElementById("dobError").textContent =
      "Date of Birth is required";
    return false;
  }

  if (gender === "") {
    alert("Please select a gender");
    return false;
  }

  if (role === "") {
    alert("Please select a role");
    return false;
  }

  if (!agreeTerms) {
    document.getElementById("termsError").textContent =
      "Please agree to the terms and conditions";
    return false;
  }

  return true;
}

function subscribe() {
  if (!validateForm()) {
    return;
  }

  alert("You subscribed!");
}
