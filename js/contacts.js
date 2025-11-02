class ContactForm {
    constructor() {
        this.contactForm = document.getElementById('contactForm');
        this.nameInput = document.getElementById('contactName');
        this.emailInput = document.getElementById('contactEmail');
        this.messageInput = document.getElementById('contactMessage');
        this.nameError = document.getElementById('nameError');
        this.emailError = document.getElementById('emailError');
        this.messageError = document.getElementById('messageError');
        
        this.init();
    }

    init() {
        this.contactForm.addEventListener('submit', (e) => this.handleSubmit(e));
        
        // Валидация 
        this.nameInput.addEventListener('blur', () => this.validateName());
        this.emailInput.addEventListener('blur', () => this.validateEmail());
        this.messageInput.addEventListener('blur', () => this.validateMessage());
        
        // ошибки при вводе
        this.nameInput.addEventListener('input', () => this.clearError(this.nameInput, this.nameError));
        this.emailInput.addEventListener('input', () => this.clearError(this.emailInput, this.emailError));
        this.messageInput.addEventListener('input', () => this.clearError(this.messageInput, this.messageError));
    }

    handleSubmit(e) {
        e.preventDefault();
        
        const isNameValid = this.validateName();
        const isEmailValid = this.validateEmail();
        const isMessageValid = this.validateMessage();
        
        if (isNameValid && isEmailValid && isMessageValid) {
            this.sendForm();
        }
    }

    validateName() {
        const name = this.nameInput.value.trim();
        
        if (!name) {
            this.showError(this.nameInput, this.nameError, 'Имя обязательно для заполнения');
            return false;
        }
        
        if (name.length < 2) {
            this.showError(this.nameInput, this.nameError, 'Имя должно содержать минимум 2 символа');
            return false;
        }
        
        this.clearError(this.nameInput, this.nameError);
        return true;
    }

    validateEmail() {
        const email = this.emailInput.value.trim();
        const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        
        if (!email) {
            this.showError(this.emailInput, this.emailError, 'Email обязателен для заполнения');
            return false;
        }
        
        if (!emailRegex.test(email)) {
            this.showError(this.emailInput, this.emailError, 'Введите корректный email адрес');
            return false;
        }
        
        this.clearError(this.emailInput, this.emailError);
        return true;
    }

    validateMessage() {
        const message = this.messageInput.value.trim();
        
        if (!message) {
            this.showError(this.messageInput, this.messageError, 'Сообщение обязательно для заполнения');
            return false;
        }
        
        if (message.length < 10) {
            this.showError(this.messageInput, this.messageError, 'Сообщение должно содержать минимум 10 символов');
            return false;
        }
        
        this.clearError(this.messageInput, this.messageError);
        return true;
    }

    showError(input, errorElement, message) {
        input.classList.add('is-invalid');
        errorElement.textContent = message;
    }

    clearError(input, errorElement) {
        input.classList.remove('is-invalid');
        errorElement.textContent = '';
    }

    sendForm() {
        const formData = {
            name: this.nameInput.value.trim(),
            email: this.emailInput.value.trim(),
            message: this.messageInput.value.trim(),
            timestamp: new Date().toISOString()
        };
        
        this.saveToLocalStorage(formData);
        this.showSuccessMessage();
        this.contactForm.reset();
        
        this.clearError(this.nameInput, this.nameError);
        this.clearError(this.emailInput, this.emailError);
        this.clearError(this.messageInput, this.messageError);
    }

    saveToLocalStorage(formData) {
        let submissions = JSON.parse(localStorage.getItem('contactSubmissions')) || [];
        submissions.push(formData);
        localStorage.setItem('contactSubmissions', JSON.stringify(submissions));
    }

    showSuccessMessage() {
        const existingMessage = document.querySelector('.alert-success');
        if (existingMessage) {
            existingMessage.remove();
        }
        
        const successMessage = document.createElement('div');
        successMessage.className = 'alert alert-success alert-dismissible fade show';
        successMessage.innerHTML = `
            <strong>Успешно!</strong> Сообщение отправлено. Я свяжусь с вами в ближайшее время.
            <button type="button" class="btn-close" data-bs-dismiss="alert"></button>
        `;

        this.contactForm.parentNode.insertBefore(successMessage, this.contactForm);
        
        setTimeout(() => {
            if (successMessage.parentNode) {
                successMessage.remove();
            }
        }, 5000);
    }
}

document.addEventListener('DOMContentLoaded', () => {
    new ContactForm();
});