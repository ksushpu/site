class DiaryManager {
    constructor() {
        this.progressList = document.getElementById('progressList');
        this.addRecordBtn = document.getElementById('addRecordBtn');
        this.addRecordSection = document.getElementById('addRecordSection');
        this.addRecordForm = document.getElementById('addRecordForm');
        this.recordForm = document.getElementById('recordForm');
        this.cancelBtn = document.getElementById('cancelBtn');

        this.records = this.loadRecords();
        this.init();
    }

    init() {
        this.renderRecords();
        this.setupEventListeners();
    }

    setupEventListeners() {
        this.addRecordBtn.addEventListener('click', () => this.showForm());
        this.cancelBtn.addEventListener('click', () => this.hideForm());
        this.recordForm.addEventListener('submit', (e) => this.addRecord(e));
    }

    loadRecords() {
        const savedRecords = localStorage.getItem('diaryRecords');
        if (savedRecords) {
            return JSON.parse(savedRecords);
        } else {
            return [
                { id: this.generateId(), date: '2024-12-15', title: 'Верстка макета сайта', status: 'Выполнено' },
                { id: this.generateId(), date: '2024-12-10', title: 'JavaScript основы', status: 'Выполнено' },
                { id: this.generateId(), date: '2024-12-05', title: 'Работа с формами', status: 'В процессе' },
                { id: this.generateId(), date: '2024-12-01', title: 'Адаптивный дизайн', status: 'В процессе' }
            ];
        }
    }

    saveRecords() {
        localStorage.setItem('diaryRecords', JSON.stringify(this.records));
    }

    generateId() {
        return Date.now().toString(36) + Math.random().toString(36).substr(2);
    }

    showForm() {
        this.addRecordForm.classList.remove('d-none');
        this.addRecordSection.classList.add('d-none');
        document.getElementById('recordDate').value = new Date().toISOString().split('T')[0];
    }

    hideForm() {
        this.addRecordForm.classList.add('d-none');
        this.addRecordSection.classList.remove('d-none');
        this.recordForm.reset();
    }

    addRecord(e) {
        e.preventDefault();

        const date = document.getElementById('recordDate').value;
        const title = document.getElementById('recordTitle').value;
        const status = document.getElementById('recordStatus').value;

        const newRecord = {
            id: this.generateId(),
            date: date,
            title: title,
            status: status
        };

        this.records.unshift(newRecord);
        this.saveRecords();
        this.renderRecords();
        this.hideForm();
        this.showNotification('Запись успешно добавлена!');
    }

    deleteRecord(id) {
        if (confirm('Вы уверены, что хотите удалить эту запись?')) {
            this.records = this.records.filter(record => record.id !== id);
            this.saveRecords();
            this.renderRecords();
            this.showNotification('Запись удалена!');
        }
    }

    toggleStatus(id) {
        const record = this.records.find(record => record.id === id);
        if (record) {
            record.status = record.status === 'Выполнено' ? 'В процессе' : 'Выполнено';
            this.saveRecords();
            this.renderRecords();
            this.showNotification('Статус обновлен!');
        }
    }

    renderRecords() {
        this.progressList.innerHTML = '';

        if (this.records.length === 0) {
            this.progressList.innerHTML = `
                <div class="skill-item mb-3">
                    <div class="skill-header d-flex justify-content-between align-items-center mb-2">
                        <span class="skill-name fw-semibold">Нет записей</span>
                        <span class="skill-percent fw-bold">Добавьте первую запись</span>
                    </div>
                </div>
            `;
            return;
        }

        this.records.forEach(record => {
            const formattedDate = new Date(record.date).toLocaleDateString('ru-RU', {
                day: 'numeric',
                month: 'long',
                year: 'numeric'
            });

            const statusIcon = record.status === 'Выполнено' ? '✅' : '⏳';
            const statusClass = record.status === 'Выполнено' ? 'status-completed' : 'status-in-progress';

            const recordElement = document.createElement('div');
            recordElement.className = 'skill-item mb-3 progress-record position-relative';
            recordElement.innerHTML = `
                <div class="skill-header d-flex justify-content-between align-items-center mb-2">
                    <span class="skill-name fw-semibold">${formattedDate} - ${record.title}</span>
                    <span class="skill-percent fw-bold ${statusClass}" data-id="${record.id}" style="cursor: pointer;">
                        ${statusIcon} ${record.status}
                    </span>
                </div>
                <button class="delete-btn position-absolute top-0 end-0 btn btn-sm btn-danger rounded-circle" data-id="${record.id}" style="width: 24px; height: 24px; opacity: 0; transition: all 0.3s ease;">×</button>
            `;

            this.progressList.appendChild(recordElement);
        });

        this.addDeleteHandlers();
        this.addStatusHandlers();
    }

    addDeleteHandlers() {
        const deleteButtons = document.querySelectorAll('.delete-btn');
        deleteButtons.forEach(button => {
            button.addEventListener('click', (e) => {
                const id = e.target.getAttribute('data-id');
                this.deleteRecord(id);
            });
        });

        const progressRecords = document.querySelectorAll('.progress-record');
        progressRecords.forEach(record => {
            record.addEventListener('mouseenter', () => {
                const deleteBtn = record.querySelector('.delete-btn');
                deleteBtn.style.opacity = '1';
            });
            record.addEventListener('mouseleave', () => {
                const deleteBtn = record.querySelector('.delete-btn');
                deleteBtn.style.opacity = '0';
            });
        });
    }

    addStatusHandlers() {
        const statusElements = document.querySelectorAll('.skill-percent[data-id]');
        statusElements.forEach(element => {
            element.addEventListener('click', (e) => {
                const id = e.target.getAttribute('data-id');
                this.toggleStatus(id);
            });
        });
    }

    showNotification(message) {
        const existingNotification = document.querySelector('.custom-notification');
        if (existingNotification) {
            existingNotification.remove();
        }

        const notification = document.createElement('div');
        notification.className = 'custom-notification';
        notification.style.cssText = `
            position: fixed;
            top: 20px;
            right: 20px;
            background: var(--primary-color);
            color: white;
            padding: 1rem 1.5rem;
            border-radius: var(--border-radius);
            box-shadow: var(--shadow-lg);
            z-index: 1000;
            animation: slideInRight 0.3s ease;
        `;
        notification.textContent = message;

        document.body.appendChild(notification);

        setTimeout(() => {
            notification.style.animation = 'slideOutRight 0.3s ease';
            setTimeout(() => {
                notification.remove();
            }, 300);
        }, 3000);
    }
}

const style = document.createElement('style');
style.textContent = `
    @keyframes slideInRight {
        from {
            transform: translateX(100%);
            opacity: 0;
        }
        to {
            transform: translateX(0);
            opacity: 1;
        }
    }

    @keyframes slideOutRight {
        from {
            transform: translateX(0);
            opacity: 1;
        }
        to {
            transform: translateX(100%);
            opacity: 0;
        }
    }

    .status-completed {
        color: #10b981 !important;
    }

    .status-in-progress {
        color: #f59e0b !important;
    }

    .skill-percent[data-id] {
        transition: all 0.3s ease;
        padding: 0.25rem 0.5rem;
        border-radius: 20px;
        background: rgba(255, 255, 255, 0.1);
    }

    .skill-percent[data-id]:hover {
        transform: scale(1.05);
        background: rgba(255, 255, 255, 0.2);
    }

    @media (max-width: 768px) {
        .delete-btn {
            opacity: 1 !important;
        }
    }
`;
document.head.appendChild(style);

document.addEventListener('DOMContentLoaded', () => {
    new DiaryManager();
});