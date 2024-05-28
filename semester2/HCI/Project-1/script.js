// ========= Download Function ==========

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
