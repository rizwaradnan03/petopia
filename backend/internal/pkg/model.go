package pkg

import "petopia-backend/internal/schema"

func ModelsToMigrate() []interface{} {

	return []interface{}{
		&schema.User{},
	}
}
