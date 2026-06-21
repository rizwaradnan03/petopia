package schema

import (
	"petopia-backend/internal/enums"
	"time"
	"github.com/google/uuid"
)

type User struct {
	ID           uuid.UUID                   `gorm:"type:uuid;primaryKey;default:uuid_generate_v4()" json:"id"`
	Username     string                   	 `gorm:"unique" json:"username"`
	Password     *string                     `gorm:"size:255" json:"-"`
	Role         enums.RoleType              `gorm:"type:varchar(20);default:'USER'" json:"role"`

	CreatedAt time.Time `json:"created_at"`
	UpdatedAt time.Time `json:"updated_at"`

	Inventory     []*Inventory   `gorm:"foreignKey:UserID;constraint:OnUpdate:CASCADE,OnDelete:SET NULL;" json:"inventory,omitempty"`
}

type Inventory struct {
	ID           uuid.UUID                   `gorm:"type:uuid;primaryKey;default:uuid_generate_v4()" json:"id"`
	UserID  uuid.UUID `json:"user_id"`
	Texture		string	`gorm:"size:255" json:"texture"`

	User *User `json:"user,omitempty"`

	CreatedAt time.Time `json:"created_at"`
	UpdatedAt time.Time `json:"updated_at"`
}