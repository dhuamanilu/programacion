public function dispatch() {

		$this->header(); //1

		$step = empty( $_GET['step'] ) ? 0 : (int) $_GET['step']; //2 && 3

		switch ( $step ) {

			case 0: //4
				$this->greet(); //5
				break;//6

			case 1://7
				check_admin_referer( 'import-upload' ); //8

				if ( $this->handle_upload() ) { //9

					if ( $this->id ) { //10
						$file = get_attached_file( $this->id ); //11
					} else { 
						$file = ABSPATH . $this->file_url; //12
					}

					add_filter( 'http_request_timeout', array( $this, 'bump_request_timeout' ) ); //13

					$this->import( $file ); //14
				} else {
					$this->import_error( $this->import_error_message ); //15
				}
				break;//16
		}

		$this->footer();//17
	